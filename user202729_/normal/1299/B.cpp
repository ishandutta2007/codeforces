#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


template<class T,class U>
struct point{
	T x,y;
	point constexpr operator+(point p)const{return {x+p.x,y+p.y};}
	point constexpr operator-(point p)const{return {x-p.x,y-p.y};}
	point constexpr operator*(T f)const{return {x*f,y*f};}

	point constexpr& operator+=(point p){return *this=*this+p;}
	point constexpr& operator-=(point p){return *this=*this-p;}
	point constexpr& operator*=(T f    ){return *this=*this*f;}

	template<class T1,class U1>
	constexpr operator point<T1,U1>() const {return {(T1)x,(T1)y};}

#define COMPAREOP(OP) bool constexpr operator OP(point p) const {return std::tie(x,y) OP std::tie(p.x,p.y);}
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	U constexpr cross(point p)const{return x*(U)p.y-y*(U)p.x;}
	U constexpr dot  (point p)const{return x*(U)p.x+y*(U)p.y;}
	U constexpr sqrlen()const{return dot(*this);}

	friend U cross(point a,point b,point c){
		return (b-a).cross(c-a);
	} // >0: ccw

	friend std::istream& operator>>(std::istream& str,point& p){
		return str>>p.x>>p.y;
	}
};

using pt=point<int,int64_t>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	if(n%2==0){
		std::vector<pt> a(n);
		for(auto& p: a) std::cin>>p;
		auto const sum1=a[0]+a[n/2];
		for(int i=0;;++i){
			if(i==n/2){
				std::cout<<"Yes\n";
				return 0;
			}
			if(a[i]+a[i+n/2]!=sum1)
				break;
		}
	}
	std::cout<<"No\n";
	return 0;
}