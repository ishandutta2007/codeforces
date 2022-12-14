#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll f[1000001][3],a[1000001],b[1000001];
int n,m;
void get(ll x){
	for(ll i=2; i*i<=x; ++i){
		if(!(x%i))
			for(b[++m]=i; !((x/=i)%i); );
	}
	if(x>1)
		b[++m]=x;
}
ll solve(ll x,ll p,ll q){
	memset(f,63,sizeof(f));
	f[0][0]=0;
	for(int i=1; i<=n; ++i){
		if(a[i]%x==0){
			f[i][0]=f[i-1][0];
			f[i][2]=min(f[i-1][1],f[i-1][2]);
		}
		else
			if((a[i]-1)%x==0||(a[i]+1)%x==0){
				f[i][0]=f[i-1][0]+q;
				f[i][2]=min(f[i-1][1],f[i-1][2])+q;
			}
		f[i][1]=min(f[i-1][0],f[i-1][1])+p;
	}
	return min(min(f[n][0],f[n][1]),f[n][2]);
}
int main(){
	ll p,q;
	scanf("%d%lld%lld",&n,&p,&q);
	for(int i=1; i<=n; ++i)
		scanf("%lld",a+i);
	get(a[n]),
	get(a[1]),
	get(a[n]-1);
	get(a[1]-1);
	get(a[n]+1),
	get(a[1]+1),
	sort(b+1,b+m+1);
	ll ans=1e18;
	unique(b+1,b+m+1);
	for(int i=1; i<=m; ++i)
		ans=min(ans,solve(b[i],p,q));
	printf("%lld",ans);
	return 0;
}