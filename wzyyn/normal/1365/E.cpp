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
ll a[505],ans;
int n;
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,n) For(j,i,n) For(k,j,n)
		ans=max(ans,a[i]|a[j]|a[k]);
	cout<<ans<<endl;
}
int main(){
	solve();
}