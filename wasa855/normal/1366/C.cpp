#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 35
int a[N][N];
pii fa[N][N];
int cx[N][N],cy[N][N];
pii find(int x,int y)
{
	return mp(x,y)==fa[x][y]?mp(x,y):fa[x][y]=find(fa[x][y].fir,fa[x][y].sec);
}
void work()
{
	memset(cx,0,sizeof(cx)); memset(cy,0,sizeof(cy));
	int n=read(),m=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) fa[i][j]=mp(i,j);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int id=i+j-1;
			int k=n+m-id;
			for(int x=1;x<=n;x++)
			{
				int y=k-x+1;
				if(x<1||x>n||y<1||y>m) continue;
				// printf("-- %d %d %d %d\n",i,j,x,y);
				if(i>x||j>y) continue;
				fa[find(i,j).fir][find(i,j).sec]=find(x,y);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			pii u=find(i,j);
			// printf("%d %d %d %d\n",i,j,u.fir,u.sec);
			if(a[i][j]==0) cx[u.fir][u.sec]++;
			else cy[u.fir][u.sec]++;
		}
	}
	// for(int i=1;i<=n;i++)
	// {
		// for(int j=1;j<=m;j++) printf("%d %d\n",cx[i][j],cy[i][j]);
		// cout<<"\n";
	// }
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans+=min(cx[i][j],cy[i][j]);
	cout<<ans<<endl;
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}