#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
struct point{
	int x,y;
	int dist(point p)const{return std::abs(x-p.x)+std::abs(y-p.y);}
};
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int npoint;std::cin>>npoint;
	std::vector<point> pts(npoint);
	for(auto& p:pts)std::cin>>p.x>>p.y;
	auto p=std::minmax_element(pts.begin(),pts.end(),[](point a,point b){return a.x<b.x;});
	auto q=std::minmax_element(pts.begin(),pts.end(),[](point a,point b){return a.y<b.y;});
	auto minx=*p.first;
	auto maxx=*p.second;
	auto miny=*q.first;
	auto maxy=*q.second;

	auto const solveTria=[&](auto a,auto b){
		// find the triangle with max perimeter and contain 2 pts a & b
		int ans=0;
		for(auto p:pts)ans=std::max(ans,a.dist(p)+b.dist(p));
		return ans+a.dist(b);
	};
	std::cout<<std::max({
			solveTria(minx,miny),solveTria(minx,maxy),
			solveTria(maxx,miny),solveTria(maxx,maxy)});
	std::string z=' '+std::to_string(minx.dist(miny)+miny.dist(maxx)+maxx.dist(maxy)+maxy.dist(minx));
	for(int _=npoint-3;_-->0;)std::cout<<z;
	std::cout<<'\n';
}