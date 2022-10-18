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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 505
int fa[N*N*2],n,m;
char s[N][N];
int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
int getid(int x,int y) {return (x-1)*m+y;}
int dx[]={-1,1,0,0},dy[]={0,0,1,-1};
int ans[N][N];
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=2;i<n;i++) for(int j=2;j<m;j++)
	{
		if(s[i][j]=='.') continue;
		int cnt=0;
		for(int k=0;k<4;k++)
		{
			int tx=i+dx[k],ty=j+dy[k];
			if(s[tx][ty]=='.') cnt++;
		}
		if(cnt&1) {cout<<"NO\n"; return 0;}
	}
	for(int i=1;i<=2*n*m;i++) fa[i]=i;
	cout<<"YES\n";
	for(int i=1;i<n;i++) for(int j=1;j<m;j++)
	{
		if(s[i][j]=='.'&&s[i+1][j+1]=='.')
		{
			int u=getid(i,j),v=getid(i+1,j+1);
			fa[find(u)]=find(v+n*m),fa[find(u+n*m)]=find(v);
		}
	}
	for(int i=1;i<n;i++) for(int j=2;j<=m;j++)
	{
		if(s[i][j]=='.'&&s[i+1][j-1]=='.')
		{
			int u=getid(i,j),v=getid(i+1,j-1);
			fa[find(u)]=find(v+n*m),fa[find(u+n*m)]=find(v);
		}
	}
	for(int i=2;i<n;i++) for(int j=2;j<m;j++)
	{
		if(s[i][j]!='X') continue;
		if(s[i-1][j]=='.'&&s[i+1][j]=='.'&&s[i][j+1]!='.')
		{
			int u=getid(i-1,j),v=getid(i+1,j);
			fa[find(u)]=find(v+n*m),fa[find(u+n*m)]=find(v);
		}
		if(s[i][j-1]=='.'&&s[i][j+1]=='.'&&s[i+1][j]!='.')
		{
			int u=getid(i,j-1),v=getid(i,j+1);
			fa[find(u)]=find(v+n*m),fa[find(u+n*m)]=find(v);
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		int u=getid(i,j);
		if(find(u)!=find(1)&&find(u+n*m)!=find(1)) fa[find(u)]=find(1);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		if(s[i][j]=='.')
		{
			if(find(getid(i,j))==find(1)) ans[i][j]=1;
			else ans[i][j]=4;
		}
		else
		{
			int cnt=0;
			for(int k=0;k<4;k++)
			{
				int tx=i+dx[k],ty=j+dy[k];
				if(s[tx][ty]=='.') cnt++;
			}
			ans[i][j]=cnt/2*5;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",ans[i][j]," \n"[j==m]);
	return 0;
}