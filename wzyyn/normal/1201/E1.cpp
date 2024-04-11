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
const int dx[]={-2,-2,-1,-1,1,1,2,2};
const int dy[]={-1,1,-2,2,-2,2,-1,1};
int dis[2][N][N];
pii from[2][N][N];
pii q[N*N],W,B;
int n,m;
void SSSP(int fl,int sx,int sy){
	For(i,1,n) For(j,1,m) dis[fl][i][j]=-1;
	int h=0,t=1;
	q[1]=pii(sx,sy);
	dis[fl][sx][sy]=0;
	while (h!=t){
		int x=q[++h].fi,y=q[h].se;
		For(d,0,7){
			int nx=x+dx[d],ny=y+dy[d];
			if (nx<1||nx>n||ny<1||ny>m||dis[fl][nx][ny]!=-1) continue;
			from[fl][nx][ny]=pii(x,y);
			dis[fl][nx][ny]=dis[fl][x][y]+1;
			q[++t]=pii(nx,ny);
		}
	}
}
pii get(){
	int x,y;
	scanf("%d %d",&x,&y);
	return pii(x,y);
}
void output(pii x){
	printf("%d %d\n",x.fi,x.se);
	fflush(stdout);
}
void check(){
	For(i,0,7)
		if (W.fi+dx[i]==B.fi)
			if (W.se+dy[i]==B.se){
				output(B);
				exit(0);
			}
}
void solve1(int fl){
	puts(fl?"BLACK":"WHITE");
	fflush(stdout);
	if (fl) W=B,B=get();
	check();
	for (;;){
		if (!dis[fl][W.fi][W.se]) exit(0);
		output(W=from[fl][W.fi][W.se]);
		if (!dis[fl][W.fi][W.se]) exit(0);
		B=get(); check();
	}
}
void solve2(int fl){
	puts(fl?"BLACK":"WHITE");
	fflush(stdout);
	if (fl) W=B,B=get();
	check();
	for (;;){
		if (!dis[fl^1][W.fi][W.se]) break;
		output(W=from[fl^1][W.fi][W.se]);
		B=get(); check();
	}
	output(W=pii(W.fi+(fl?1:-1),W.se-2)); B=get(); check();
	output(W=pii(W.fi-2,W.se+1)); B=get(); check();
	output(W=pii(W.fi+2,W.se+1)); exit(0);
}
int main(){
	scanf("%d%d",&n,&m);
	W=get(); B=get();
	SSSP(0,n/2,m/2);
	SSSP(1,n/2+1,m/2);
	if ((W.fi+B.fi+W.se+B.se)&1){
		if (dis[0][W.fi][W.se]<=dis[1][B.fi][B.se]) solve1(0);
		if (dis[1][W.fi][W.se]>=dis[1][B.fi][B.se]+2) solve1(1);
		solve2(0);
	}
	else{
		if (dis[0][W.fi][W.se]-1>=dis[1][B.fi][B.se]) solve1(1);
		if (dis[0][W.fi][W.se]+1<=dis[0][B.fi][B.se]) solve1(0);
		solve2(1);
	}
}