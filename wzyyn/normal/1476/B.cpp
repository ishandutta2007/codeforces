#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
using namespace std;
int n,k;
ll a[105];
bool check(ll v){
	v+=a[1];
	For(i,2,n){
		if (k*v<100ll*a[i]) return 0;
		v+=a[i];
	}
	return 1;
}
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%lld",&a[i]);
	ll l=0,r=(1ll<<50),ans=-1;
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}