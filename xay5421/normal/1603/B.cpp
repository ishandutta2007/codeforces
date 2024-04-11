// author: xay5421
// created: Sat Oct 30 22:38:43 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		LL x,y;
		scanf("%lld%lld",&x,&y);
		if(x>y){
			printf("%lld\n",x*y+y);
		}else if(x==y){
			printf("%lld\n",x);
		}else{
			if(((x+y)/2-x)<x){
				printf("%lld\n",(x+y)/2);
			}else{
				LL k=(y%x)/2;
				printf("%lld\n",y-k);
			}
		}
	}
	return 0;
}