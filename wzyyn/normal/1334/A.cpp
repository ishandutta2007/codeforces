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
int n,a[105],b[105];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&a[i],&b[i]);
	For(i,1,n)
		if (b[i]-b[i-1]>a[i]-a[i-1]||b[i]<b[i-1]||a[i]<a[i-1])
			return puts("NO"),void(0);
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}