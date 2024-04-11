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
int n,a[N],c[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) c[i]=0;
	For(i,1,n) scanf("%d",&a[i]);
	For(i,2,n) if (a[i]!=a[i-1]) ++c[a[i-1]];
	//For(i,1,n) if (i!=a[n]) ++c[i];
	For(i,1,n) if (i!=a[1]) ++c[i];
	int ans=1<<30;
	For(i,1,n) ans=min(ans,c[a[i]]);//cout<<c[a[i]]<<' ',cout<<endl;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}