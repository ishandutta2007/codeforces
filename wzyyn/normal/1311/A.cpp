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
	int x,y;
	scanf("%d%d",&x,&y);
	if (x==y) puts("0");
	else if (x<y) puts((x+y)&1?"1":"2");
	else puts((x+y)&1?"2":"1");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}