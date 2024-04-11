// it's not that hard...
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

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	using P=Point_<int, int64_t>;
	std::vector<P> points(n); for(auto& [x, y]: points) std::cin>>x>>y;
	std::vector<char> used(n);
	int last=0; used[0]=true;
	std::cout<<last+1;
	for(int _=0; _<n-1; ++_){
		int best=-1; int64_t maxNorm=INT_MIN;
		for(int next=0; next<n; ++next) if(not used[next])
			if(auto const curNorm=points[next].squaredDistance(points[last]); curNorm>maxNorm){
				maxNorm=curNorm; best=next;
			}
		last=best;
		used[last]=true;
		std::cout<<' '<<last+1;
	}
	std::cout<<'\n';
}