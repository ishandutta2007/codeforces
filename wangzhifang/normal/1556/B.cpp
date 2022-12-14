#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100000
int a[max_n+1],vis[max_n+1];
il void test(){
	int n,cnt[2]={0,0};
	scanf("%d",&n);
	for(int i=1; i<=n; ++i){
		scanf("%d",a+i);
		++cnt[a[i]&=1];
	}
	if(abs(cnt[0]-cnt[1])>1){
		puts("-1");
		return;
	}
	memset(vis+1,0,n<<2);
	ll ans=0;
	if(cnt[0]>cnt[1]){
		for(int i=1,j=1,k=1,pv=0; i<=n; ++i){
			while(j<=n&&(vis[j]||(a[j]&1))){
				pv-=vis[j];
				++j;
			}
			while(k<=n&&(vis[k]||!(a[k]&1))){
				pv-=vis[k];
				++k;
			}
			if((i&1)){
				if(j>k)
					ans+=j-k-pv,++pv;
				vis[j]=1;
				++j;
			}
			else{
				if(j<k)
					ans+=k-j-pv,++pv;
				vis[k]=1;
				++k;
			}
		}
	}
	else
		if(cnt[0]<cnt[1]){
			for(int i=1,j=1,k=1,pv=0; i<=n; ++i){
				while(j<=n&&(vis[j]||!(a[j]&1))){
					pv-=vis[j];
					++j;
				}
				while(k<=n&&(vis[k]||(a[k]&1))){
					pv-=vis[k];
					++k;
				}
				if((i&1)){
					if(j>k)
						ans+=j-k-pv,++pv;
					vis[j]=1;
					++j;
				}
				else{
					if(j<k)
						ans+=k-j-pv,++pv;
					vis[k]=1;
					++k;
				}
			}
		}
		else{
			ll t=0;
			#define ans t
			for(int i=1,j=1,k=1,pv=0; i<=n; ++i){
				while(j<=n&&(vis[j]||(a[j]&1))){
					pv-=vis[j];
					++j;
				}
				while(k<=n&&(vis[k]||!(a[k]&1))){
					pv-=vis[k];
					++k;
				}
//				printf(" %d %d %d\n",j,k,pv);
				if((i&1)){
					if(j>k)
						ans+=j-k-pv,++pv;
					vis[j]=1;
					++j;
				}
				else{
					if(j<k)
						ans+=k-j-pv,++pv;
					vis[k]=1;
					++k;
				}
			}
			#undef ans
	memset(vis+1,0,n<<2);
			for(int i=1,j=1,k=1,pv=0; i<=n; ++i){
				while(j<=n&&(vis[j]||!(a[j]&1))){
					pv-=vis[j];
					++j;
				}
				while(k<=n&&(vis[k]||(a[k]&1))){
					pv-=vis[k];
					++k;
				}
//				printf(" %d %d %d\n",j,k,pv);
				if((i&1)){
					if(j>k)
						ans+=j-k-pv,++pv;
					vis[j]=1;
					++j;
				}
				else{
					if(j<k)
						ans+=k-j-pv,++pv;
					vis[k]=1;
					++k;
				}
			}
			if(t<ans)
				ans=t;
		}
	printf("%lld\n",ans);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}