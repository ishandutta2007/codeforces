#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

struct rect{
	int x1,y1,x2,y2;

	bool valid()const{
		return x1<=x2 and y1<=y2;
	}

	bool inside(rect r)const{
		return r.x1<=x1 and x2<=r.x2 and r.y1<=y1 and y2<=r.y2;
	}

	int ask()const{
		std::cout<<"? "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<std::endl;
		int x;std::cin>>x;
		return x;
	}
};

rect solve(int n,auto ok){
	rect ans{1,1,n,n};

	for(int step=1<<20;step;step>>=1){
		ans.x1+=step;
		if(!ans.valid() or !ok(ans)) ans.x1-=step;
	}
	for(int step=1<<20;step;step>>=1){
		ans.y1+=step;
		if(!ans.valid() or !ok(ans)) ans.y1-=step;
	}
	for(int step=1<<20;step;step>>=1){
		ans.x2-=step;
		if(!ans.valid() or !ok(ans)) ans.x2+=step;
	}
	for(int step=1<<20;step;step>>=1){
		ans.y2-=step;
		if(!ans.valid() or !ok(ans)) ans.y2+=step;
	}
	return ans;
}

int main(){
	int n;std::cin>>n;
	rect r1=solve(n,[](rect r){return r.ask()>0;});
	rect r2=solve(n,[r1](rect r){return r.ask()-(int)r1.inside(r)>0;});
	std::cout<<"! "
		<<r1.x1<<' '<<r1.y1<<' '<<r1.x2<<' '<<r1.y2<<' '
		<<r2.x1<<' '<<r2.y1<<' '<<r2.x2<<' '<<r2.y2<<'\n';
}