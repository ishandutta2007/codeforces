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
int n,Q;
int vis[2][100005];
int ans;
void UPD(int x,int y,int v){
	if (vis[x][y]&&vis[x^1][y]) ans+=v;
	
	if (vis[x][y]&&vis[x^1][y-1]) ans+=v;
	if (vis[x][y]&&vis[x^1][y+1]) ans+=v;
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		UPD(x,y,-1);
		vis[x][y]^=1;
		UPD(x,y,1);
		if (!ans) puts("Yes");
		else puts("No");
	}
}