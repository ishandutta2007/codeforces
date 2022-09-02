// author: xay5421
// created: Mon Feb  8 00:14:19 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
int L,R;
struct ff{
	int x,y,z;
	ff(int x,int y,int z):x(x),y(y),z(z){}
};
vector<ff>e;
void out(int n){
	printf("YES\n%d %d\n",n,int(e.size()));
	for(const auto&x:e)printf("%d %d %d\n",x.x,x.y,x.z);
	exit(0);
}
int main(){
	scanf("%d%d",&L,&R);
	int n=2;
	e.emplace_back(1,2,L);
	R-=L;
	if(R==0)out(n);
	if(R==1){
		R+=L;
		e.clear();
		n=3;
		e.emplace_back(1,3,L);
		e.emplace_back(1,2,R-1);
		e.emplace_back(2,3,1);
		out(n);
	}
	--R;
	n=32;
	rep(i,12,31)rep(j,i+1,31){
		e.emplace_back(i,j,1<<(31-j));
	}
	rep(i,12,31)e.emplace_back(i,32,1);
	rep(i,0,19)if(R>>i&1){
		R^=1<<i;
		e.emplace_back(2,31-i,R+1);
	}
	e.emplace_back(1,32,R+L);
	e.emplace_back(2,32,R+1);
	out(n);
	return 0;
}