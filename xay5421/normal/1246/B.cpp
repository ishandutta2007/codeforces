#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=100005;
int n,K,a[N],maxx,cnt[N],w[N];
LL val[N];
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&K);
	for(int i=1;i<=100000;i+=1){
		w[i]=i;
		rep(x,2,i/x)if(i%x==0&&i/x%x==0){
			w[i]=w[i/x/x];
			break;
		}
	}
	if(K>2){
		rep(x,1,100000){
			LL pw=1;
			rep(_,1,K){
				pw*=x;
				if(pw>(LL)1e10){
					break;
				}
			}
			if(pw>(LL)1e10)break;
			maxx=x;
			val[x]=pw;
		}
	}
	LL ans=0;
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(K==2){
			a[i]=w[a[i]];
			ans+=cnt[a[i]];
			++cnt[a[i]];
		}else{
			rep(j,1,maxx){
				if(val[j]%a[i]==0&&val[j]/a[i]<=100000){
					ans+=cnt[val[j]/a[i]];
				}
			}
			++cnt[a[i]];
		}
	}
	printf("%lld\n",ans);
	return 0;
}