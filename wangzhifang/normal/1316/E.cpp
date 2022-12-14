#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define max_n 100000
struct node{
	ll v,s[8];
	friend bool operator <(const node&x,const node&y){
		return x.v>y.v;
	}
};
node a[max_n+1];
ll f[max_n+1][128];
int main(){
	int n,p,k;
	memset(f,172,sizeof(f));
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1; i<=n; ++i)
		scanf("%lld",&a[i].v);
	for(int i=1; i<=n; ++i)
		for(int j=0; j<p; ++j)
			scanf("%lld",a[i].s+j);
	sort(a+1,a+n+1);
	f[0][0]=0;
	for(int i=1; i<=n; ++i)
		for(int b=0,cnt=0; b<(1<<p); ++b,cnt=0){
			for(int k=0; k<p; ++k)
				if((1ll<<k)&b)
					++cnt,f[i][b]=max(f[i][b],f[i-1][b^(1ll<<k)]+a[i].s[k]);
			f[i][b]=max(f[i][b],f[i-1][b]+(i<=cnt+k?a[i].v:0));
		}
	printf("%lld\n",f[n][(1<<p)-1]);
	return 0;
}