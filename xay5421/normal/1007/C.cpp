#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
LL n;
int main(){
	scanf("%lld",&n);
	LL x=0,y=0,dx=n,dy=n;
	while(1){
		printf("%lld %lld\n",x+dx,y+dy);
		fflush(stdout);
		int z;
		scanf("%d",&z);
		if(z==0){
			return 0;
		}else if(z==1){
			x+=dx;
			dx=min(n-x,dx*2);
		}else if(z==2){
			y+=dy;
			dy=min(n-y,dy*2);
		}else{
			dx=max(1LL,dx>>1),dy=max(1LL,dy>>1);
		}
	}
	return 0;
}