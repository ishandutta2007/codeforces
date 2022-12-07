#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define y1 fdhjksa
using namespace std;
const int N=2005;
int col[2][N][N];
int n,m,k,x,y,mx,nd;
int S[N][2],id[N][2];
int Id[N][N],ans[N];
void dfs(int p,int x,int y,int c0,int c1){
	int t=col[p^1][y][c0];
	col[p][x][c0]=y;
	col[p^1][y][c0]=x;
	if (!t){
		col[p^1][y][c1]=0;
		return;
	}
	dfs(p^1,y,t,c1,c0);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if (k==1){
		For(i,1,m) printf("1\n");
		return 0;
	}
	For(i,1,n) scanf("%*d");
	For(i,1,n) S[i][0]=S[i][1]=k;
	For(i,1,m){
		scanf("%d%d",&x,&y);
		if (S[x][0]==k) S[x][0]=0,id[x][0]=++nd;
		if (S[y][1]==k) S[y][1]=0,id[y][1]=++nd;
		++S[x][0]; ++S[y][1];
		x=id[x][0]; y=id[y][1];
		Id[x][y]=i;
		int c0=1,c1=1;
		for (;col[0][x][c0];++c0);
		for (;col[1][y][c1];++c1);
		mx=max(mx,max(c0,c1));
		if (!col[1][y][c0]){
			col[0][x][c0]=y;
			col[1][y][c0]=x;
			continue;
		}
		if (!col[0][x][c1]){
			col[0][x][c1]=y;
			col[1][y][c1]=x;
			continue;
		}
		dfs(0,x,y,c0,c1);
	}
	For(i,1,nd) For(j,1,k)
		if (col[0][i][j]) ans[Id[i][col[0][i][j]]]=j;
	For(i,1,m) printf("%d\n",ans[i]);
}