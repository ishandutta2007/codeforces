#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int npoint;std::cin>>npoint;
	struct point{
		int x;
		int64_t y;

		point operator-(point a)const{return {x-a.x,y-a.y};}
		int64_t cross(point a)const{return x*a.y-y*a.x;}
	};
	std::vector<point> pts(npoint);
	for(point& p:pts){
		std::cin>>p.x>>p.y;
		p.y-=p.x*(int64_t)p.x;
	}

	/*
	 * idea: the problem becomes ~ but with lines instead of u-shaped
	 * parabolas when each point (x,y) is changed to (x,y-x**2)
	 */

	std::sort(begin(pts),end(pts),[](point a,point b){
			return a.x!=b.x?a.x<b.x:a.y<b.y;
			});

	auto endout=begin(pts);  // reuse pts array to hold output (upper bound) array
	for(point p:pts){
		while((
				endout-begin(pts)>=2&&
				(p-endout[-1]).cross(endout[-2]-endout[-1])>=0
			  )||(
				endout!=begin(pts)&&
				p.x==endout[-1].x
			  ))
			--endout;
		*endout++=p;
	}

	std::cout<<endout-begin(pts)-1<<'\n';
}