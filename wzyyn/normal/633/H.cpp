#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=30005;
int n,Q,mo,L[N],R[N];
int cnt[N],f[N];
pii a[N];
ll ans[N];
int main(){
	scanf("%d%d",&n,&mo);
	For(i,1,n){
		scanf("%d",&a[i].fi);
		a[i].se=i;
	}
	sort(a+1,a+n+1);
	scanf("%d",&Q);
	For(i,1,Q) scanf("%d%d",&L[i],&R[i]);
	For(i,1,n) f[i]=(i==1?1:f[i-1]+f[i-2])%mo;
	For(i,1,n){
		int v=a[i].fi%mo,pp=a[i].se;
		int p=(i==1||a[i].fi!=a[i-1].fi?-1:a[i-1].se);
		For(j,1,Q) if (p<L[j]&&L[j]<=pp&&pp<=R[j])
			ans[j]+=v*f[++cnt[j]];
	}
	For(i,1,Q)
		printf("%lld\n",ans[i]%mo);
}