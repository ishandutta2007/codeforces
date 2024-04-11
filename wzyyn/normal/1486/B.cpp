#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

int n,x[1005],y[1005];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	if (n%2==1) puts("1");
	else printf("%lld\n",(x[n/2+1]-x[n/2]+1)*1ll*(y[n/2+1]-y[n/2]+1));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}