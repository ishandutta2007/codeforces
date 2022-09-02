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
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int h,g;
		scanf("%d%d",&h,&g);
		int n=(1<<h)-1;
		vector<int>a(n+1);
		rep(i,1,n)scanf("%d",&a[i]);
		vector<int>dp(n+1);
		auto up=[&](int x){
			if(a[x]){
				int lc=x*2<=n?a[x*2]:0;
				int rc=x*2+1<=n?a[x*2+1]:0;
				if(!lc&&!rc){
					dp[x]=x;
				}else if(!lc){
					dp[x]=dp[x*2+1];
				}else if(!rc){
					dp[x]=dp[x*2];
				}else{
					dp[x]=a[x*2]<a[x*2+1]?dp[x*2+1]:dp[x*2];
				}
			}
		};
		per(i,n,1){
			up(i);
		}
		function<void(int)>f=[&](int x){
			int lc=x*2<=n?a[x*2]:0;
			int rc=x*2+1<=n?a[x*2+1]:0;
			if(lc==0&&rc==0){
				dp[x]=0;
				a[x]=0;
			}else{
				if(lc>rc){
					a[x]=lc;
					f(x*2);
				}else{
					a[x]=rc;
					f(x*2+1);
				}
				up(x);
			}
		};
		vector<int>v;
		rep(i,1,n){
			if(dp[i]>=(1<<g)){
				v.push_back(i);
				f(i);
				/*D("dp={");
				rep(j,1,n){
					D("%d,",dp[j]);
				}
				D("}\n");
				D("a={");
				rep(j,1,n){
					D("%d,",a[j]);
				}
				D("}\n");*/
				--i;
			}
		}
		int m=(1<<g)-1;
		long long sum=0;
		rep(i,1,m)sum+=a[i];
		printf("%lld\n",sum);
		for(auto&x:v)printf("%d ",x);
		puts("");
	}
	return 0;
}