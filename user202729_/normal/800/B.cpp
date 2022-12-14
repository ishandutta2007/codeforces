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

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<point> points(number);
	for(auto &[x, y]: points) std::cin>>x>>y;

	double result=DBL_MAX;
	point c=points.end()[-2], b=points.back();
	for(int index=0; index<number; ++index){
		auto const a=points[index];
		result=std::min(result,
				(double)std::abs((a-b).cross(c-b))/(std::sqrt(a.squaredDistance(c))*2)
				);

		c=b; b=a;
	}
	std::cout<<std::fixed<<std::setprecision(10)<<result<<'\n';

}