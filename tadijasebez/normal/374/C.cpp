#include <bits/stdc++.h>
using namespace std;
void ckmx(int &x,int y){x=max(x,y);}
const int N=1050;
int dp[N][N];
bool cyc[N][N];
int col[N][N];
char base[N][N];
map<char,char> nxt;
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void DFS(int x, int y){
	col[x][y]=2;
	dp[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+mv[i][0];
		int ny=y+mv[i][1];
		if(base[nx][ny]==nxt[base[x][y]]){
			if(!col[nx][ny]){
				DFS(nx,ny);
			}else if(col[nx][ny]==2)cyc[x][y]=1;
			ckmx(dp[x][y],dp[nx][ny]+1);
			cyc[x][y]|=cyc[nx][ny];
		}
	}
	col[x][y]=1;
}
int main(){
	nxt['D']='I';nxt['I']='M';nxt['M']='A';nxt['A']='D';
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",base[i]+1);
	int ans=0;
	bool can=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(base[i][j]=='D')
				DFS(i,j),
				ckmx(ans,dp[i][j]/4),
				can|=cyc[i][j];
	if(can)printf("Poor Inna!\n");
	else if(ans==0)printf("Poor Dima!\n");
	else printf("%i\n",ans);
	return 0;
}