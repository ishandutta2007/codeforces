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

void solve(){
	int x,n,m;
	scanf("%d%d%d",&x,&n,&m);	
	For(i,1,n) if (x>20) x=x/2+10;
	For(i,1,m) x-=10;
	puts(x<=0?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}