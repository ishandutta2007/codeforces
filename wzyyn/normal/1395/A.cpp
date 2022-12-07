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
	int r,g,b,w;
	scanf("%d%d%d%d",&r,&g,&b,&w);
	if ((r&1)+(g&1)+(b&1)+(w&1)<=1) puts("Yes");
	else if (r&&g&&b&&(r&1)+(g&1)+(b&1)+(w&1)>=3) puts("Yes");
	else puts("No");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}