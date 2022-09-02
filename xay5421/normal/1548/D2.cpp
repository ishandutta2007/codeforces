// author: xay5421
// created: Mon Aug  2 14:37:29 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=6006;
int n,x[N],y[N];
int cnt[64];
LL ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&x[i],&y[i]);
	rep(i,1,n){
		memset(cnt,0,sizeof(cnt));
		rep(j,1,n)if(i!=j){
			int dd=__gcd(abs(x[i]-x[j]),abs(y[i]-y[j]))&3;
			int dx=(x[j]-x[i])&3;
			int dy=(y[j]-y[i])&3;
			++cnt[dd<<4|dx<<2|dy];
		}
		rep(j,0,63)if(cnt[j]){
			int jd=j>>4,jx=j>>2&3,jy=j&3;
			rep(k,j,63)if(cnt[k]){
				int kd=k>>4,kx=k>>2&3,ky=k&3;
				if((jd&1)!=(kd&1))continue;
				int td=__gcd(abs(jx-kx),abs(jy-ky))&3;
				if(td&1)continue;
				if(((jx*ky-jy*kx)&3)==((jd+kd+td)&3)){
					ans+=(j==k?cnt[j]*(cnt[j]-1)/2:cnt[j]*cnt[k])*(jd&1?3:1);
				}
			}
		}
	}
	printf("%lld\n",ans/3);
	return 0;
}