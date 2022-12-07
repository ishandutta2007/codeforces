#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int mo=1000000007;
const int N=10000005;
int n,mu[N],cnt[N],P[500005],x;
int main(){
	scanf("%d",&n);
	For(i,P[0]=1,n) P[i]=2ll*P[i-1]%mo;
	For(i,1,n) scanf("%d",&x),++cnt[x];
	mu[1]=1;
	ll ans=0;
	For(i,1,N-1){
		if (!mu[i]) continue;
		For(j,2,(N-1)/i) mu[i*j]-=mu[i],cnt[i]+=cnt[i*j];
		if (!cnt[i]||cnt[i]==n) continue;
		ans-=1ll*mu[i]*(P[cnt[i]]-1)*(n-cnt[i])%mo;
	}
	ans=(ans%mo+mo)%mo;
	printf("%lld\n",ans);
}