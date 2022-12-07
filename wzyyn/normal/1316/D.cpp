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
const int N=1005;
int v[N][N][2],n;
char ans[N][N];
void dfs(int x,int y){
	if (x!=1&&v[x-1][y][0]==v[x][y][0]&&v[x-1][y][1]==v[x][y][1])
		if (!ans[x-1][y]) ans[x-1][y]='D',dfs(x-1,y);
	if (x!=n&&v[x+1][y][0]==v[x][y][0]&&v[x+1][y][1]==v[x][y][1])
		if (!ans[x+1][y]) ans[x+1][y]='U',dfs(x+1,y);
	if (y!=1&&v[x][y-1][0]==v[x][y][0]&&v[x][y-1][1]==v[x][y][1])
		if (!ans[x][y-1]) ans[x][y-1]='R',dfs(x,y-1);
	if (y!=n&&v[x][y+1][0]==v[x][y][0]&&v[x][y+1][1]==v[x][y][1])
		if (!ans[x][y+1]) ans[x][y+1]='L',dfs(x,y+1);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) For(j,1,n)
		scanf("%d%d",&v[i][j][0],&v[i][j][1]);
	For(i,1,n) For(j,1,n)
		if (v[i][j][0]==i&&v[i][j][1]==j){
			ans[i][j]='X';
			dfs(i,j);
		}
	For(i,1,n) For(j,1,n)
		if (v[i][j][0]==-1){
			if (i!=1&&v[i-1][j][0]==-1) ans[i][j]='U';
			if (i!=n&&v[i+1][j][0]==-1) ans[i][j]='D';
			if (j!=1&&v[i][j-1][0]==-1) ans[i][j]='L';
			if (j!=n&&v[i][j+1][0]==-1) ans[i][j]='R';
		}
	For(i,1,n) For(j,1,n)
		if (!ans[i][j])
			return puts("INVALID"),0;
	puts("VALID");
	For(i,1,n) printf("%s\n",ans[i]+1);
}