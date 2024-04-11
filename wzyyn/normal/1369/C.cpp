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
const int N=500005;
int n,m,a[N],b[N],v[N];
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,m) scanf("%d",&b[i]);
	sort(a+1,a+n+1,greater<int>());
	sort(b+1,b+m+1);
	ll ans=0;
	int p=0;
	For(i,1,m){
		v[i]=a[++p];
		ans+=v[i];
	}
	For(i,1,m){
		For(j,2,b[i]) v[i]=min(v[i],a[++p]);
		ans+=v[i];
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}