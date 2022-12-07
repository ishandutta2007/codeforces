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
#define all(v) v.begin(),v.end()
using namespace std;
int n,m;
pii a[100005];
ll S[100005];
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,m) scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a+1,a+m+1);
	reverse(a+1,a+m+1);
	For(i,1,m) S[i]=S[i-1]+a[i].fi;
	ll ans=S[min(n,m)];
	For(i,1,m){
		int l=1,r=m,p=0;
		while (l<=r){
			int mid=(l+r)/2;
			if (a[mid].fi>a[i].se)
				p=mid,l=mid+1;
			else r=mid-1;
		}
		if (p+(a[i].se<a[i].fi)<=n){
			ll co=S[p];
			if (a[i].se>=a[i].fi)
				co+=a[i].fi,++p;
			ans=max(ans,1ll*(n-p)*a[i].se+co);
		}
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}