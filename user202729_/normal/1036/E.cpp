// http://codeforces.com/contest/1036/problem/E
#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<unordered_map>
#include<algorithm>
auto&I=std::cin;auto&O=std::cout;
constexpr double eps=1e-9;
struct point{
	double x,y;
	size_t hash()const{
		return size_t(x)*1009+size_t(y);
	}
	point operator+(point a)const{
		return {x+a.x,y+a.y};
	}
	point operator-(point a)const{
		return {x-a.x,y-a.y};
	}
	point operator*(double a)const{
		return {x*a,y*a};
	}
	bool operator==(point a)const{
		return x==a.x&&y==a.y;
	}
	bool round(){
		if(std::abs(std::round(x)-x)>eps)
			return false;
		if(std::abs(std::round(y)-y)>eps)
			return false;
		x=std::round(x);
		y=std::round(y);
		return true;
	}
	double cross(point a)const{
		return x*a.y-y*a.x;
	}
	std::pair<double,double> decompose(point a,point b)const{
		double d=a.cross(b);
		return {this->cross(b)/d,a.cross(*this)/d};
	}
};
std::ostream& operator<<(std::ostream& str,point p){
	return str<<p.x<<','<<p.y;
}

struct segment{
	point a,b;
	std::pair<bool,point> intersect(segment s)const{
		point v1=b-a,v2=s.b-s.a,target=s.b-a;
		double d=v1.cross(v2);
		if(d==0)
			return {false,{0,0}};
		double f1=target.cross(v2)/d,f2=v1.cross(target)/d;
		if(f1<-eps||f1>1+eps||f2<-eps||f2>1+eps)
			return {false,{0,0}};
		return {true,a+v1*f1};
	}
};
int main(){
	std::ios::sync_with_stdio(0);I.tie(0);
	int nSegment;I>>nSegment;

	std::vector<segment> segments(nSegment);
	int nLatticePoint=0;
	for(segment& s:segments){
		I>>s.a.x>>s.a.y>>s.b.x>>s.b.y;
		point v=s.a-s.b;
		nLatticePoint+=1+std::abs(std::__gcd<int>(v.x,v.y));
	}

	auto hash_point=[](point a){
		return a.hash();
	};
	std::unordered_map<point,int,decltype(hash_point)> nIntersectPair(0,hash_point);

	for(int i=1;i<nSegment;++i)for(int j=0;j<i;++j){
		segment s1=segments[i],s2=segments[j];
		// compute the intersection of s1 and s2
		auto z=s1.intersect(s2);
		if(not z.first)continue;
		point p=z.second;
		if(not p.round()){
			continue;
		}
		++nIntersectPair[p];
	}

	for(auto z:nIntersectPair){
		int x=z.second;
		nLatticePoint-=int(std::round(std::sqrt(x*8+1)))/2;
	}
	O<<nLatticePoint<<'\n';
}