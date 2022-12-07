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
	int x,y,x1,y1,x2,y2,a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
	if (x==x1&&x==x2&&(a||b)) return puts("NO"),void(0);
	if (y==y1&&y==y2&&(c||d)) return puts("NO"),void(0);
	x+=b-a; y+=d-c;
	puts(x1<=x&&x<=x2&&y1<=y&&y<=y2?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}