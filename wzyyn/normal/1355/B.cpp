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
const int N=100005;
int n,a[500005],f[500005];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	For(i,1,n) if (i>=a[i]) f[i]=max(f[i-1],f[max(i-a[i],0)]+1);
	else f[i]=f[i-1];
	printf("%d\n",f[n]);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}