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
const int N=200005;
int n,q[N];
pii a[N];
ll ans;
struct Tarr{
	ll t[N];
	void change(int x,int v){
		for (;x;x-=x&(-x)) t[x]+=v;
	}
	ll ask(int x){
		ll ans=0;
		for (;x<=n;x+=x&(-x)) ans+=t[x];
		return ans; 
	}
}tr1,tr2;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i].fi);
	For(i,1,n) scanf("%d",&a[i].se);
	For(i,1,n) q[i]=a[i].se;
	sort(q+1,q+n+1);
	sort(a+1,a+n+1);
	For(i,1,n) a[i].se=lower_bound(q+1,q+n+1,a[i].se)-q;
	Rep(i,n,1){
		ans+=tr2.ask(a[i].se);
		ans-=1ll*a[i].fi*tr1.ask(a[i].se);
		//cout<<i<<' '<<a[i].se<<' '<<tr1.ask(a[i].se)<<endl;
		tr2.change(a[i].se,a[i].fi);
		tr1.change(a[i].se,1);
	}
	printf("%lld\n",ans);
}
/*
a.p<b.p a.v<b.v
*/