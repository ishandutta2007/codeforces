#include<bits/stdc++.h>
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=500005,INF=0X3F3F3F3F;
int n,a[N],cnt[N],sum[N],pre[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),++cnt[a[i]];
	rep(i,1,N-1)pre[i]=cnt[i]?i:pre[i-1],sum[i]=sum[i-1]+cnt[i];
	LL ans=0;
	rep(y,2,N-1){
		LL tt=0;
		for(int i=y;i<N;i+=y){
			tt+=1LL*(sum[min(i+y-1,N-1)]-sum[i-1])*(i/y);
		}
		pair<int,int>mx{~INF,~INF},smx{~INF,~INF};
		auto put=[&](int k1){
			pair<int,int>cur{k1%y,k1};
			if(mx<cur)smx=mx,mx=cur;
			else if(smx<cur)smx=cur;
		};
		for(int i=N/y*y;i>=0;i-=y){
			int num=pre[min(N-1,i+y-1)];
			int can=(mx.X>=0)+(smx.X>=0);
			if(num>=i){
				put(num);
				if(cnt[num]==1)num=pre[num-1];
				if(num>=i){
					put(num);
				}
			}
			if(mx.X>=0){
				int x=min((LL)(i+mx.X)/2,tt-(i/y));
				if(x>1)ans=max(ans,1LL*x*y);
			}
			if(smx.X>=0){
				int x=min((LL)i+smx.X,tt-2*(i/y));
				if(x>1)ans=max(ans,1LL*x*y);
				if(can+(mx.Y<=i+y-1)>1){
					x=min((LL)i+mx.X,tt-2*(i/y)-1);
					if(x>1)ans=max(ans,1LL*x*y);
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}