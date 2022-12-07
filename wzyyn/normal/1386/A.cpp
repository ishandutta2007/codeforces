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
ll n;
int query(ll x){
	cout<<"? "<<x<<endl;
	cin>>x;
	return x;
} 
void solve(){
	scanf("%lld",&n);
	ll delta=0,p0=n;
	ll l=1,r=n-1,f=0;
	for (;l<=r;){
		ll mid=(l+r)/2;
		delta+=(!f?mid:-mid);
		p0=min(p0,n-delta);
		l=mid+1; f^=1;
	}
	l=1,r=n-1; f=0;
	ll ans=n;
	query(p0);
	for (;l<=r;){
		ll mid=(l+r)/2;
		ll np0=p0+(!f?mid:-mid);
		if (query(np0)) ans=mid,r=mid-1;
		else l=mid+1;
		f^=1; p0=np0;
	}
	cout<<"= "<<ans<<endl;
	
}
int main(){
	int T;
	scanf("%lld",&T);
	while (T--) solve();
}