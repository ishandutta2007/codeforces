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
int n,m;
char s[N][N];
int vis[N][N];
pii q[N*N];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
void color(int sx,int sy){
	int h=0,t=1;
	q[1]=pii(sx,sy); vis[sx][sy]=1;
	while (h!=t){
		int x=q[++h].fi,y=q[h].se;
		For(d,0,3){
			int nx=x+dx[d],ny=y+dy[d];
			if (s[nx][ny]=='#'&&!vis[nx][ny])
				vis[nx][ny]=1,q[++t]=pii(nx,ny);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",s[i]+1);
	int s1=0,s2=0;
	For(i,1,n){
		int fl=0;
		For(j,1,m)
			if (s[i][j]=='#'){
				if (fl&&s[i][j-1]!='#') return puts("-1"),0;
				fl=1;
			}
		if (!fl) ++s1;
	}
	For(j,1,m){
		int fl=0;
		For(i,1,n)
			if (s[i][j]=='#'){
				if (fl&&s[i-1][j]!='#') return puts("-1"),0;
				fl=1;
			}
		if (!fl) ++s2;
	}
	if (s1==0&&s2) return puts("-1"),0;
	if (s2==0&&s1) return puts("-1"),0;
	int ans=0;
	For(i,1,n) For(j,1,m)
		if (!vis[i][j]&&s[i][j]=='#')
			ans++,color(i,j);
	printf("%d\n",ans);
}