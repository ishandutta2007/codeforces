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
const int dx[]={-1,1,0,0};
const int dy[]={0,0,1,-1};
const int N=1005;
int n,m,Q,h,t;
char s[N][N];
ll dis[N][N];
pii q[N*N];
void ext(int x,int y,int d){
	if (dis[x][y]!=1ll<<60) return;
	q[++t]=pii(x,y);
	dis[x][y]=d; 
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,n) For(j,1,m) dis[i][j]=1ll<<60;
	For(i,1,n) For(j,1,m-1)
		if (s[i][j]==s[i][j+1])
			ext(i,j,0),ext(i,j+1,0);
	For(i,1,n-1) For(j,1,m)
		if (s[i][j]==s[i+1][j])
			ext(i,j,0),ext(i+1,j,0);
	while (h!=t){
		int x=q[++h].fi,y=q[h].se;
		For(d,0,3){
			int nx=x+dx[d],ny=y+dy[d];
			if (nx<1||nx>n||ny<1||ny>m) continue;
			ext(nx,ny,dis[x][y]+1);
		}
	}
	while (Q--){
		int x,y; ll T;
		scanf("%d%d%lld",&x,&y,&T);
		if (T<=dis[x][y]) putchar(s[x][y]);
		else putchar(s[x][y]^((T-dis[x][y])&1));
		puts("");
	}
}