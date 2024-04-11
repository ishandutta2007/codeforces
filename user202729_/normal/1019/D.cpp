// intended solution.
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

template<class T,class U>
struct Point_{
	T x,y;
	Point_ constexpr operator+(Point_ p)const{return {x+p.x,y+p.y};}
	Point_ constexpr operator-(Point_ p)const{return {x-p.x,y-p.y};}
	Point_ constexpr operator*(T f)const{return {x*f,y*f};}

	Point_ constexpr& operator+=(Point_ p){return *this=*this+p;}
	Point_ constexpr& operator-=(Point_ p){return *this=*this-p;}
	Point_ constexpr& operator*=(T f    ){return *this=*this*f;}

	template<class T1,class U1>
	constexpr operator Point_<T1,U1>() const {return {(T1)x,(T1)y};}

#define COMPAREOP(OP) bool constexpr operator OP(Point_ p) const {return std::tie(x,y) OP std::tie(p.x,p.y);}
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	U constexpr cross(Point_ p)const{return x*(U)p.y-y*(U)p.x;}
	U constexpr dot  (Point_ p)const{return x*(U)p.x+y*(U)p.y;}
	U constexpr squaredLength()const{return dot(*this);}
	U constexpr squaredDistance(Point_ p)const{return (*this-p).squaredLength();}

	friend U cross(Point_ a,Point_ b,Point_ c){
		return (b-a).cross(c-a);
	} // >0: ccw

	friend std::istream& operator>>(std::istream& str,Point_& p){
		return str>>p.x>>p.y;
	}
};

using point=Point_<int, int64_t>;

point sortDirection;

template<class T> struct Condition{
	T data;
};
template<class T> Condition(T)-> Condition<T>;

struct Compare{ // if sortDirection is x+ then this sorts first by increasing y then by increasing x
	using is_transparent=int;
	auto key(point it) const{
		return std::pair(sortDirection.cross(it), sortDirection.dot(it));
	}
	bool operator()(point first, point sec) const{
		return key(first)<key(sec);
	}
	template<class T>
	bool operator()(Condition<T> condition, point it) const{
		return condition.data(it);
	}
	// set.upper_bound(Condition{lambda}) = first element such that lambda returns true
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; int64_t expectedArea; std::cin>>number>>expectedArea;
	std::vector<point> points(number);
	for(auto &[x, y]: points) std::cin>>x>>y;

	struct Direction{
		point first, sec;
		point diff() const{return first-sec;}
	};
	std::vector<Direction> directions; directions.reserve((number*(number-1))>>1);
	for(auto const& sec: points){
		for(auto const& first: points){
			if(&first==&sec) break;
			assert(first!=sec);

			auto [a, b]=std::minmax({first, sec});
			if(directions.size()>=directions.capacity()){
				assert(false); __builtin_unreachable();
			}
			directions.push_back({b, a});
		}
	}
	assert(directions.size()==directions.capacity());

	std::sort(begin(directions), end(directions),[&](auto first, auto sec){
		return first.diff().cross(sec.diff())>0;
	});


	sortDirection=directions[0].diff();
	std::set<point, Compare> pointSet(begin(points), end(points));

	std::vector<decltype(pointSet)::node_type> nodes;
	nodes.reserve(number);

	for(int index=0, last=0; index<(int)directions.size(); ++index){
		if(index!=0 and directions[index].diff().cross(directions[index-1].diff())!=0){
			for(int j=last; j<index; ++j){
				for(auto p: {directions[j].first, directions[j].sec}){
					auto node=pointSet.extract(p);
					if(node) nodes.push_back(std::move(node));
				}
			}

			// change sort direction
			sortDirection=directions[index].diff();

			// check set invariant
			assert([&]{
				if(not pointSet.empty()){
					auto last=*pointSet.begin();
					std::for_each(std::next(pointSet.begin()), pointSet.end(),[&](auto it){
						assert(pointSet.key_comp()(last, it));
						last=it;
					});
				}
				return true;
			}());

			while(not nodes.empty()){
				pointSet.insert(std::move(nodes.back())); nodes.pop_back();
			}
			last=index;
		}

		auto const [a, b]=directions[index];
		auto const diff=a-b;
		auto iterator=pointSet.upper_bound(Condition{[&](point it){
			return diff.cross(it-b)>=2*expectedArea;
		}});
		if(iterator!=pointSet.end() and diff.cross(*iterator-b)==2*expectedArea){
			std::cout<<"Yes\n";
			for(auto it: {a, b, *iterator})
				std::cout<<it.x<<' '<<it.y<<'\n';
			return 0;
		}
		
		iterator=pointSet.upper_bound(Condition{[&](point it){
			return diff.cross(it-b)>=-2*expectedArea;
		}});
		if(iterator!=pointSet.end() and diff.cross(*iterator-b)==-2*expectedArea){
			std::cout<<"Yes\n";
			for(auto it: {a, b, *iterator})
				std::cout<<it.x<<' '<<it.y<<'\n';
			return 0;
		}
	}

	std::cout<<"No\n";
}