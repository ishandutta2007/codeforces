//(unproven average time complexity)
//(what's this algorithm called? seems familiar)
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
template<class T,class U>
struct Point_{
 T x,y;
 Point_ constexpr operator+(Point_ p)const{return {x+p.x,y+p.y};}
 Point_ constexpr operator-(Point_ p)const{return {x-p.x,y-p.y};}
 Point_ constexpr operator-()const{return {-x,-y};}
 Point_ constexpr operator*(T f)const{return {x*f,y*f};}
 Point_ constexpr& operator+=(Point_ p){return *this=*this+p;}
 Point_ constexpr& operator-=(Point_ p){return *this=*this-p;}
 Point_ constexpr& operator*=(T f ){return *this=*this*f;}
 template<class T1,class U1>
 constexpr operator Point_<T1,U1>() const {return {(T1)x,(T1)y};}
 bool constexpr operator ==(Point_ p) const {return std::tie(x,y) == std::tie(p.x,p.y);} bool constexpr operator !=(Point_ p) const {return std::tie(x,y) != std::tie(p.x,p.y);} bool constexpr operator <(Point_ p) const {return std::tie(x,y) < std::tie(p.x,p.y);} bool constexpr operator >(Point_ p) const {return std::tie(x,y) > std::tie(p.x,p.y);} bool constexpr operator <=(Point_ p) const {return std::tie(x,y) <= std::tie(p.x,p.y);} bool constexpr operator >=(Point_ p) const {return std::tie(x,y) >= std::tie(p.x,p.y);}
 U constexpr cross(Point_ p)const{return x*(U)p.y-y*(U)p.x;}
 U constexpr dot (Point_ p)const{return x*(U)p.x+y*(U)p.y;}
 U constexpr squaredLength()const{return dot(*this);}
 U constexpr squaredDistance(Point_ p)const{return (*this-p).squaredLength();}
 friend U cross(Point_ a,Point_ b,Point_ c){
  return (b-a).cross(c-a);
 }
 friend std::istream& operator>>(std::istream& str,Point_& p){
  return str>>p.x>>p.y;
 }
};
using Point=Point_<short, int>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<Point> spaceships(number), bases(number);
	for(auto& it: spaceships) std::cin>>it;
	for(auto& it: bases) std::cin>>it;

	auto const mapping=[&](std::vector<Point> const& data){
		std::map<Point, int> result; // for convenience; a simple binary search is faster
		for(int i=0; i<(int)data.size(); ++i){
			assert(not result.count(data[i]));
			result[data[i]]=i;
		}
		return result;
	};
	auto map1=mapping(spaceships), map2=mapping(bases);

	std::mt19937 engine;

	auto const randomSplit=[&](std::vector<Point> a, std::vector<Point> b){
		bool const swap=std::uniform_int_distribution(0, 1)(engine);
		if(swap) std::swap(a, b);
		assert(a.size()==b.size());
		auto const index=std::uniform_int_distribution(0,(int)a.size()-1)(engine);
		std::swap(a[index], a.back());
		auto const pivot=a.back(); a.pop_back();

		struct Event{
			signed char delta; // -1 for a, 1 for b, need to find something with sum 0 or 1
			// provided that sum of all (exclude pivot) is 1, and value of pivot is -1
			signed char deltaA;
			Point direction; // point-pivot, must be > {0}
		};
		std::vector<Event> events;
		int initialValue=0; // exclude pivot
		int initialValueA{};
		auto const addEvent=[&](signed char value, Point direction, signed char valueA){
			assert(direction!=Point{});
			if(direction>Point{}){
				initialValue+=value;
				initialValueA+=valueA;
				events.push_back({(signed char)-value, (signed char)-valueA, direction}); }
			else events.push_back({value, valueA, -direction});
		};
		// <explanation>
	
		for(auto p: a) addEvent(-1, p-pivot, 1);
		for(auto p: b) addEvent(1, p-pivot, 0);

		std::sort(begin(events), end(events), [&](auto const& first, auto const& sec){
			return first.direction.cross(sec.direction)>0;
		});

		auto const splitSet=[pivot](std::vector<Point> data, Point t){
			auto const predicate=[&](auto const& it){
				return std::pair(t.cross(it-pivot), t.dot(it-pivot))>std::pair(0, 0); // keep in set 1
				// terrible mistake: NOT (it-pivot).cross(t)
			};
			auto const iterator=std::partition(begin(data), end(data), predicate);
			std::vector<Point> returnFalse(iterator, data.end());
			data.erase(iterator, data.end());

			for(auto it: data) assert(predicate(it));
			for(auto it: returnFalse) assert(not predicate(it));

			return std::pair(std::move(data), std::move(returnFalse));
		};

		assert([&]{
			for(auto x: splitSet(a, events[0].direction).first) assert(x>pivot);
			for(auto x: splitSet(a, events[0].direction).second) assert(x<pivot);
			return true;
		}());

		int minImbalance=INT_MAX;
		for(int pass=0; pass<2; ++pass){
			int value=initialValue, valueA=initialValueA;
			for(auto [delta, deltaA, direction]: events){
				assert(valueA==(int)splitSet(a, direction).first.size());
				assert(value==
						valueA*(-1)+
						(int)splitSet(b, direction).first.size()*1);

				// it's not necessary to consider the first event twice
				if(value==0 or value==1){ // right before direction->satisfies
					auto const imbalance=std::abs((int)a.size()-valueA+1 - valueA); // pivot goes into set 2
					if(pass==0){
						assert(not a.empty());
						assert(a.size()==b.size()-1); // pivot removed
						minImbalance=std::min(minImbalance, imbalance);
					}else{
						if(imbalance==minImbalance){
							auto t=value==1 ?-direction: direction; // so value'==0, exclude pivot from the set
							// in set if (cross, dot)>(0, 0)
							// sum value of set is value'


							auto [a1, a2]=splitSet(std::move(a), t); a2.push_back(pivot);
							auto [b1, b2]=splitSet(std::move(b), t);
							assert(a1.size()==b1.size()); // sum value of set (1) is 0

							if(swap){ std::swap(a1, b1); std::swap(a2, b2); }
							return std::tuple(
									std::move(a1), std::move(a2),
									std::move(b1), std::move(b2));
						}
					}
								
				}

				value+=delta;
				valueA+=deltaA;
			}
		}
		assert(false); __builtin_unreachable();

	};

	std::vector<int> result(number);
	auto work=[&](auto work, std::vector<Point> a, std::vector<Point> b){
		assert(a.size()==b.size());
		if(a.size()==1){
			result[map1.at(a[0])]=map2.at(b[0]);
			return;
		}
		if(a.empty()) return;

		auto [a1, a2, b1, b2]=randomSplit(std::move(a), std::move(b));

		work(work, std::move(a1), std::move(b1));
		work(work, std::move(a2), std::move(b2));
	};
	work(work, std::move(spaceships), std::move(bases));
	for(auto it: result) std::cout<<it+1<<'\n';
}