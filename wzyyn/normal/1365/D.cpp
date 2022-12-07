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
const int N=55;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int n,m;
char s[N][N];
int vis[N][N];
pii q[N*N];
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,n) For(j,1,m)
		if (s[i][j]=='B')
			For(d,0,3){
				int ni=i+dx[d],nj=j+dy[d];
				if (s[ni][nj]=='.') s[ni][nj]='#';
			}
	int h=0,t=0;
	memset(vis,0,sizeof(vis));
	if (s[n][m]!='#') q[++t]=pii(n,m);
	while (h!=t){
		int x=q[++h].fi,y=q[h].se;
		For(d,0,3){
			int nx=x+dx[d],ny=y+dy[d];
			if (!vis[nx][ny]&&s[nx][ny]!='#')
				if (nx>0&&ny>0&&nx<=n&&ny<=m)
					vis[nx][ny]=1,q[++t]=pii(nx,ny);
		}
	}
	For(i,1,n) For(j,1,m)
		if (s[i][j]=='B'&&vis[i][j])
			return puts("No"),void(0);
		else if (s[i][j]=='G'&&!vis[i][j])
			return puts("No"),void(0);
	puts("Yes");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}