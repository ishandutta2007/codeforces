

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

	friend std::ostream& operator<<(std::ostream& str,Point_ p){
		return str<<p.x<<' '<<p.y<<'\n';
	}

	Point_ rot() const{ return {-y, x}; } // 90 degree counterclockwise
};

using Point=Point_<double, double>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	Point p, v; int a, b, c, d;
	std::cin>>p>>v>>a>>b>>c>>d;
	v*=1/std::sqrt(v.squaredLength());

	std::cout<<std::fixed<<std::setprecision(12)
		<<p+v*b
		<<p+v.rot()*(a/2.)
		<<p+v.rot()*(c/2.)
		<<p+v.rot()*(c/2.)-v*d
		<<p-v.rot()*(c/2.)-v*d
		<<p-v.rot()*(c/2.)
		<<p-v.rot()*(a/2.)
		;
}