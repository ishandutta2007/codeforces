#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005;
int T,n,x[N],y[N],z[N],lb[4],rb[4],L[4],R[4];
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		rep(i,1,n)scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
		int l=0,r=4e18,ans[3]={0,0,0};
		while(l<=r){
			int d=(l+r)/2;
			auto push=[&](int i,int x){
				lb[i]=max(lb[i],x-d);
				rb[i]=min(rb[i],x+d);
			};
			memset(lb,192,sizeof(lb));
			memset(rb,63,sizeof(rb));
			rep(i,1,n){
				push(0,+x[i]+y[i]+z[i]);
				push(1,-x[i]+y[i]+z[i]);
				push(2,+x[i]-y[i]+z[i]);
				push(3,+x[i]+y[i]-z[i]);
			}
			bool ok=0;
			rep(i,0,1){
				bool flag=1;
				memcpy(L,lb,sizeof(L));
				memcpy(R,rb,sizeof(R));
				rep(j,0,3){
					if((L[j]&1)!=i)++L[j];
					if((R[j]&1)!=i)--R[j];
					if(L[j]>R[j])flag=0;
				}
				if(flag&&max(L[1]+L[2]+L[3],L[0])<=min(R[1]+R[2]+R[3],R[0])){
					ok=1;
					if(L[1]+L[2]+L[3]<L[0]){
						L[1]=min(R[1],L[0]-L[2]-L[3]);
					}
					if(L[1]+L[2]+L[3]<L[0]){
						L[2]=min(R[2],L[0]-L[1]-L[3]);
					}
					if(L[1]+L[2]+L[3]<L[0]){
						L[3]=min(R[3],L[0]-L[1]-L[2]);
					}
					ans[0]=(L[2]+L[3])/2;
					ans[1]=(L[1]+L[3])/2;
					ans[2]=(L[1]+L[2])/2;
				}
			}
			if(ok){
				r=d-1;
			}else{
				l=d+1;
			}
		}
		printf("%lld %lld %lld\n",ans[0],ans[1],ans[2]);
	}
	return 0;
}