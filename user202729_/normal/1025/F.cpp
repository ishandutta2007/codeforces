#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

template<class T, class U>
struct pointTemplate{
	T x,y;
	pointTemplate constexpr operator+(pointTemplate p)const{return {x+p.x,y+p.y};}
	pointTemplate constexpr operator-(pointTemplate p)const{return {x-p.x,y-p.y};}
	pointTemplate constexpr operator*(T f)const{return {x*f,y*f};}

	pointTemplate constexpr& operator+=(pointTemplate p){return *this=*this+p;}
	pointTemplate constexpr& operator-=(pointTemplate p){return *this=*this-p;}
	pointTemplate constexpr& operator*=(T f    ){return *this=*this*f;}

	template<class T1,class U1>
	constexpr operator pointTemplate<T1,U1>() const {return {(T1)x,(T1)y};}

#define COMPAREOP(OP) bool constexpr operator OP(pointTemplate p) const {return std::tie(x,y) OP std::tie(p.x,p.y);}
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	U constexpr cross(pointTemplate p)const{return x*(U)p.y-y*(U)p.x;}
	U constexpr dot  (pointTemplate p)const{return x*(U)p.x+y*(U)p.y;}
	U constexpr sqrlen()const{return dot(*this);}

	friend U cross(pointTemplate a,pointTemplate b,pointTemplate c){
		return (b-a).cross(c-a);
	} // >0: ccw

	friend std::istream& operator>>(std::istream& str,pointTemplate& p){
		return str>>p.x>>p.y;
	}
};

using point=pointTemplate<int, int64_t>;


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<point> points(number);
	for(auto & p: points) std::cin>>p;

	int64_t result=0;
	for(int secIndex=0;secIndex<number;++secIndex) {
		auto const sec=points[secIndex];
		auto rest=points; rest[secIndex]=rest.back(); rest.pop_back();
		{
			auto iterator=std::partition(begin(rest),end(rest), [&](auto other){return other<sec;});
			auto compareSec=[&](auto x, auto y){return cross(sec, x, y)>0;};
			std::sort(begin(rest), iterator, compareSec);
			std::sort(iterator, end(rest), compareSec);
		}

		auto const realSize=number-1; assert(realSize==(int)rest.size());
		rest.reserve(rest.size()*2);
		auto const realEnd=end(rest);

		//rest.insert(realEnd,begin(rest),realEnd);
		// (what? This is undefined behavior? No way...)

		rest.resize(rest.size()*2);
		std::copy(begin(rest), realEnd, realEnd);
		
		std::vector<int> halfSize(realSize);
		// halfSize[index]=number of points such that cross(sec, rest[index], x)>0

		for(int indexFirst=0, opIndex=1;indexFirst<realSize;++indexFirst) {
			auto const first=rest[indexFirst];
			if(opIndex==indexFirst) ++opIndex;
			while(cross(first, rest[opIndex], sec)>0) ++opIndex;
			halfSize[indexFirst]=opIndex-indexFirst;
		}

		std::vector<int64_t> value(realSize);
		std::transform(begin(halfSize),end(halfSize), begin(value),[&](int64_t x){
			x=realSize-x;
			return (x*(x-1))>>1;
		});

		std::vector<int64_t> value1;
		value1.reserve(value.size()*2+1);
		value1.insert(end(value1),begin(value),end(value));
		value1.insert(end(value1),begin(value),end(value));
		value1.push_back(value[0]);
		std::partial_sum(value1.rbegin(), value1.rend(), value1.rbegin());

		std::vector<int64_t> value2(value1.size());
		std::partial_sum(value1.rbegin(), value1.rend(), value2.rbegin());

		for(int indexFirst=0;indexFirst<realSize;++indexFirst) {
			auto const& first=rest[indexFirst];

			result-=value2[indexFirst+halfSize[indexFirst]] -value2[indexFirst+realSize];

			result+=value1[indexFirst+halfSize[indexFirst]]*
				(realSize-halfSize[indexFirst]);
		}
	}

	std::cout<<(result>>1)<<'\n';

}