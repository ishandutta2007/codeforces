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
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
const int N=105;
const int M=5000005;
const int mo=998244353;
pll a[N],b[N],q[M];
int n,m,tot,ans;
int S(ll l,ll r){
	int v1=(l+r)%mo,v2=(r-l+1)%mo;
	return 1ll*v1*v2%mo*(mo+1)/2%mo;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld%lld",&a[i].fi,&a[i].se);
	sort(a+1,a+n+1);
	int top=1;
	For(i,2,n)
		if (a[i].fi<=a[top].se+1)
			a[top].se=max(a[top].se,a[i].se);
		else a[++top]=a[i];
	n=top;
	scanf("%d",&m);
	For(i,1,m) scanf("%lld%lld",&b[i].fi,&b[i].se);
	sort(b+1,b+m+1);
	top=1;
	For(i,2,m)
		if (b[i].fi<=b[top].se+1)
			b[top].se=max(b[top].se,b[i].se);
		else b[++top]=b[i];
	m=top;
	For(i,1,n) For(j,1,m) Rep(k,60,0){
		ll bl1=(a[i].fi-1)>>k,br1=(a[i].se+1)>>k;
		ll bl2=(b[j].fi-1)>>k,br2=(b[j].se+1)>>k;
		int f1=!(bl1&1),f2=(br1&1),f3=!(bl2&1),f4=(br2&1);
		if (bl1+1>=br1) f1=f2=0; if (bl2+1>=br2) f3=f4=0;
		//printf("%d %d %d %lld %lld %lld %lld %d %d %d %d\n",i,j,k,bl1,br1,bl2,br2,f1,f2,f3,f4);
		if ((f1&&b[j].fi!=((bl2+1)<<k))||(f3&&a[i].fi!=((bl1+1)<<k))) q[++tot]=pll((bl1^bl2^1)<<k,k);
		if ((f2&&b[j].fi!=((bl2+1)<<k))||(f3&&a[i].se+1!=(br1<<k)))   q[++tot]=pll((br1^bl2^1)<<k,k);
		if ((f1&&b[j].se+1!=(br2<<k))  ||(f4&&a[i].fi!=((bl1+1)<<k))) q[++tot]=pll((bl1^br2^1)<<k,k);
		if ((f2&&b[j].se+1!=(br2<<k))  ||(f4&&a[i].se+1!=(br1<<k)))   q[++tot]=pll((br1^br2^1)<<k,k);
		if (f1&&f3) q[++tot]=pll((bl1^bl2)<<k,k);
		if (f2&&f3) q[++tot]=pll((br1^bl2)<<k,k);
		if (f1&&f4) q[++tot]=pll((bl1^br2)<<k,k);
		if (f2&&f4) q[++tot]=pll((br1^br2)<<k,k);
	}
	sort(q+1,q+tot+1);
	For(i,1,tot) q[i].se=q[i].fi+(1ll<<q[i].se)-1;
	/*printf("INFO %d %d\n",n,m);
	For(i,1,n) printf("%lld %lld\n",a[i].fi,a[i].se);
	For(i,1,m) printf("%lld %lld\n",b[i].fi,b[i].se);
	For(i,1,tot) printf("%lld %lld\n",q[i].fi,q[i].se);*/
	top=1;
	For(i,2,tot)
		if (q[i].fi<=q[top].se+1)
			q[top].se=max(q[top].se,q[i].se);
		else q[++top]=q[i];
	For(i,1,top)
		ans=(ans+S(q[i].fi,q[i].se))%mo;
	printf("%d\n",ans);
}