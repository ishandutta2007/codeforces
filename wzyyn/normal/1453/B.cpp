#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
using namespace std;
int n,a[500005];
void solve(){
	ll ans=0,mx=0;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,2,n) ans+=abs(a[i]-a[i-1]);
	mx=max(abs(a[2]-a[1]),abs(a[n]-a[n-1]));
	For(i,2,n-1) mx=max(mx,1ll*abs(a[i]-a[i-1])+abs(a[i]-a[i+1])-abs(a[i-1]-a[i+1]));
	cout<<ans-mx<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}