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
#define double long double
using namespace std;
const int mo=1000000007;
const int N=1000005;
int n,k,a[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	if (k==1) return cout<<(n&1)<<endl,void(0);
	sort(a+1,a+n+1,greater<int>());
	ll v=0,pos=a[1],ans=0;
	For(i,1,n){
		for (;pos>a[i]&&v&&v<1ll<<30;--pos)	v=min(1ll<<40,v*k);
		if (v) ans=(ans+mo-power(k,a[i]))%mo,v--;
		else ans=(ans+power(k,a[i]))%mo,v++;
		pos=a[i];
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}