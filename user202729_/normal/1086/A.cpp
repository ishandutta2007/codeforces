#include<iostream>
#include<vector>

struct p{int x,y;};
int main(){
	p a,b,c;
	std::cin
		>>a.x>>a.y
		>>b.x>>b.y
		>>c.x>>c.y;
	std::vector<p> pts;
	auto crop=[&](p& b,p a,p c){
		while(b.x<std::min(a.x,c.x)){
			pts.push_back(b);
			++b.x;
		}
		while(b.x>std::max(a.x,c.x)){
			pts.push_back(b);
			--b.x;
		}
		while(b.y<std::min(a.y,c.y)){
			pts.push_back(b);
			++b.y;
		}
		while(b.y>std::max(a.y,c.y)){
			pts.push_back(b);
			--b.y;
		}
	};
	crop(b,a,c);
	crop(a,b,b);
	crop(c,b,b);
	pts.push_back(b);
	std::cout<<pts.size()<<'\n';
	for(auto a:pts)std::cout<<a.x<<' '<<a.y<<'\n';
}