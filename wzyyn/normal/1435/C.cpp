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
const int N=100005;
ll n,a[N],b[N],top;
pii q[N*10];
bool cmp(pii x,pii y){
	return b[x.fi]-a[x.se]<
		   b[y.fi]-a[y.se];
}
int main(){
	For(i,1,6) scanf("%lld",&a[i]);
	sort(a+1,a+7,greater<int>());
	a[7]=-(1ll<<40);
	scanf("%lld",&n);
	For(i,1,n) scanf("%lld",&b[i]);
	For(i,1,n) For(j,1,6)
		q[++top]=pii{i,j};
	sort(q+1,q+top+1,cmp);
	ll mn=1ll<<40,mx=0;
	For(i,1,n){
		mx=max(mx,b[i]-a[1]);
		mn=min(mn,b[i]-a[1]);
	}
	ll ans=mx-mn;
	//cout<<mx<<' '<<mn<<endl;
	For(i,1,top){
		mx=max(mx,b[q[i].fi]-a[q[i].se+1]);
		if (mx>(1ll<<30)) break;
		//cout<<mx<<' '<<b[q[i+1].fi]-a[q[i+1].se]<<endl;
		ans=min(ans,mx-b[q[i+1].fi]+a[q[i+1].se]);
	}
	cout<<ans<<endl;
}