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
int n,k,a[N],f[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n-1) if (a[i]<a[i+1]&&a[i]+1!=a[i+1]) return puts("No"),void(0);
	puts("Yes");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}