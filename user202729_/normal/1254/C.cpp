#ifndef LOCAL
#define NDEBUG
#endif
#include<numeric>
#include<cassert>
#include<vector>
#include<algorithm>
#include<cassert>
#include<iostream>

#ifdef LOCAL

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
};
std::vector<pt> pts{
	{0,0},{0,1},{1,2},{2,2},{2,1},{1,0}
};

int getn(){
	return (int)pts.size();
}
int64_t area(int i,int j,int k){
	auto x=pts[j]-pts[i];
	auto y=pts[k]-pts[i];
	auto c=x.cross(y);
	assert(c);
	return c<0?-c:c;
}
int cross(int i,int j,int k){
	auto x=pts[j]-pts[i];
	auto y=pts[k]-pts[i];
	auto c=x.cross(y);
	assert(c);
	return (c>0)-(c<0);
}

#else
int getn(){
	int n;std::cin>>n;return n;
}
int64_t area(int i,int j,int k){
	std::cout<<"1 "<<i+1<<' '<<j+1<<' '<<k+1<<std::endl;
	int64_t x;std::cin>>x;
	return x;
}
int cross(int i,int j,int k){
	std::cout<<"2 "<<i+1<<' '<<j+1<<' '<<k+1<<std::endl;
	int x;std::cin>>x;
	return x;
}
#endif

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n=getn();

	int const p1=0;
	int p2=1;
	for(int i=2;i<n;++i) // n-2 queries
		if(cross(p1,p2,i)<0)
			p2=i;

	// NEVER USE PAIR
	std::vector<std::pair<int64_t,int>> z;z.reserve(n-2); // all points except p1 and p2 + area
	for(int i=1;i<n;++i)if(i!=p2){ // n-2 queries
		z.push_back({area(p1,p2,i), i});
	}
	auto [toparea,top]=*std::max_element(begin(z),end(z));
	auto iter=std::partition(begin(z),end(z),[&](std::pair<int64_t,int> p){ // true: first half
			if(p.second==top)return false;
			return cross(p2,p.second,top)>0;
			}); // n-2 queries
	std::swap(*iter,*std::find(begin(z),end(z),std::make_pair(toparea,top)));

	std::sort(begin(z),iter,[](auto m,auto n){return m.first<n.first;});
	std::sort(std::next(iter),end(z),[](auto m,auto n){return m.first>n.first;});

	std::cout<<"0 "<<p1+1<<' '<<p2+1;
	for(auto [area,i]:z)std::cout<<' '<<i+1;
	std::cout<<'\n';
}