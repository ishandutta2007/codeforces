#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>
#include<tuple>

struct pt{
	int x,y;
	pt      constexpr operator+(pt p)const{return {x+p.x,y+p.y};}
	pt      constexpr operator-(pt p)const{return {x-p.x,y-p.y};}
	bool    constexpr operator==(pt p)const{return std::tie(x,y)==std::tie(p.x,p.y);}
	bool    constexpr operator< (pt p)const{return std::tie(x,y)< std::tie(p.x,p.y);}
	bool    constexpr operator!=(pt p)const{return std::tie(x,y)!=std::tie(p.x,p.y);}
	int64_t constexpr cross(pt p)const{return x*(int64_t)p.y-y*(int64_t)p.x;}
	int64_t constexpr dot  (pt p)const{return x*(int64_t)p.x+y*(int64_t)p.y;}
	int64_t constexpr sqrlen()const{return dot(*this);}

	int ind;
};

int64_t cross(pt a,pt b,pt c){
	return (b-a).cross(c-a);
} // >0: ccw

std::istream& operator>>(std::istream& str,pt& p){
	return str>>p.x>>p.y;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<pt> pts(n);
	{
		int ind=0;
		for(pt& p:pts){
			std::cin>>p;
			p.ind=++ind;
		}
	}

	auto iter=std::min_element(begin(pts),end(pts));
	pt pivot=*iter;pts.erase(iter);
	std::cout<<pivot.ind;

	for(int z=n-2;z--;){
		char type;std::cin>>type;

		if(type=='L')
			iter=std::min_element(begin(pts),end(pts),[pivot](pt a,pt b){return cross(a,b,pivot)>0;});
		else
			iter=std::max_element(begin(pts),end(pts),[pivot](pt a,pt b){return cross(a,b,pivot)>0;});

		pivot=*iter;
		pts.erase(iter);
		std::cout<<' '<<pivot.ind;
	}
	assert(pts.size()==1);
	std::cout<<' '<<pts[0].ind<<std::endl;
}