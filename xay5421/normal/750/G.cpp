// author: xay5421
// created: Wed May  5 21:00:30 2021
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
typedef long long LL;
LL n,ans;
LL f[65][125][2];
int main(){
	scanf("%lld",&n);
	rep(h,1,60){
		LL x=n/((1LL<<h)-1);
		if(!x)break;
		LL need=n%((1LL<<h)-1);
		per(i,h,1)if(need>=(1LL<<i)-1)need-=(1LL<<i)-1;
		ans+=!need;
	}
	D("ans=%lld\n",ans);
	rep(l,1,60)rep(r,1,60){
		LL x=(n-(1LL<<r)+1)/((1LL<<(l+1))+(1LL<<(r+1))-3);
		if(!x)break;
		LL need=(n-(1LL<<r)+1)%((1LL<<(l+1))+(1LL<<(r+1))-3);
		if(!need){++ans;continue;}
		if(l==1&&r==1){ans+=need==x*5+1;continue;}
		rep(cnt,0,l+r){
			if(cnt)++need;
			if(need&1)continue;
			memset(f,0,sizeof(f)),f[0][0][0]=1;
			rep(i,1,60){
				int v=need>>i&1;
				rep(j,0,(i-1)*2)rep(k,0,1)if(f[i-1][j][k]){
					rep(x,0,i<l)rep(y,0,i<r){
						if(((k+x+y)&1)==v){
							f[i][j+x+y][(k+x+y)>>1]+=f[i-1][j][k];
						}
					}
				}
			}
			ans+=f[60][cnt][0];
		}
	}
	printf("%lld\n",ans);
	return 0;
}