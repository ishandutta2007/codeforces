// author: xay5421
// created: Sun Nov 14 14:09:02 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
int T,n;
LL get(LL x){
	if(x<0)return 0;
	LL t=sqrt(x*2)+5;
	while(t*(t-1)/2>x)--t;
	if(t*(t-1)/2==x)return t;
	return -1;
}
LL ask(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	LL x;
	scanf("%lld",&x);
	return x;
}
LL C2(LL x){
	return x*(x-1)/2;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int l=1,r=n,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			LL x=ask(1,mid);
			if(x==0){
				l=mid+1;
			}else{
				LL t=get(x);
				if(t>1){
					ans=mid-t+1;
					if(ask(1,ans)==0){
						l=ans;
						break;
					}
				}
				r=mid-1;
			}
		}
		int res=ans;
		while(l<=r){
			int mid=(l+r)>>1;
			if(ask(ans,mid)==C2(mid-ans+1)){
				res=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		LL all=ask(1,n);
		printf("! %d %d %lld\n",ans,res+1,res+get(all-C2(res-ans+1)));
		fflush(stdout);
	}
	return 0;
}