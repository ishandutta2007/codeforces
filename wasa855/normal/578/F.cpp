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
int mod;
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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int Inv(int x){return qpow(x,mod-2);}
#define N 305
int n,m;
char s[N][N];
int getid(int x,int y){return (x-1)*(m+1)+y;}
int fa[N*N];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
int a[N][N],col[N][N];
int u[N*N],v[N*N],cnt;
int C=0;
int Guass()
{
	int n=C; 
	n--;
	bool ne=0;
	for(int i=1;i<=n;i++)
	{
		int id=i;
		for(int j=i+1;j<=n;j++) if(a[j][i]) id=j;
		if(id!=i)
		{
			ne^=1;
			for(int j=1;j<=n;j++) swap(a[i][j],a[id][j]);
		}
		if(a[i][i]==0) {n++; return 0;}
		int r=Inv(a[i][i]);
		for(int j=i+1;j<=n;j++)
		{
			int ned=mul(a[j][i],r);
			for(int k=1;k<=n;k++) a[j][k]=sub(a[j][k],mul(ned,a[i][k]));
		}
	}
	int ans=1; for(int i=1;i<=n;i++) ans=mul(ans,a[i][i]);
	n++;
	if(ne) ans=sub(0,ans);
	return ans;
}
int rev[N*N];
int count()
{
	for(int i=1;i<=C;i++) for(int j=1;j<=C;j++) a[i][j]=0;
	for(int i=1;i<=cnt;i++)
	{
		int x=rev[u[i]],y=rev[v[i]];
		a[x][x]=add(a[x][x],1),a[y][y]=add(a[y][y],1);
		a[x][y]=sub(a[x][y],1),a[y][x]=sub(a[y][x],1);
	}
	int r=Guass();
	return r;
}
int solve1()
{
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) fa[getid(i,j)]=getid(i,j); 
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		if(s[i][j]=='\\'&&col[i][j]==0&&col[i+1][j+1]==0)
		{
			int u=find(getid(i,j)),v=find(getid(i+1,j+1));
			if(u==v) return 0;
			fa[u]=v;
		}
		if(s[i][j]=='/'&&col[i+1][j]==0&&col[i][j+1]==0)
		{
			int u=find(getid(i+1,j)),v=find(getid(i,j+1));
			if(u==v) return 0;
			fa[u]=v;
		}
	}
	C=0; cnt=0;
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++)
	{
		if(col[i][j]==0)
		{
			if(find(getid(i,j))==getid(i,j)) rev[getid(i,j)]=++C;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='*'&&find(getid(i,j))!=find(getid(i+1,j+1))&&col[i][j]==0)
			{
				u[++cnt]=find(getid(i,j)),v[cnt]=find(getid(i+1,j+1));
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='*'&&find(getid(i+1,j))!=find(getid(i,j+1))&&col[i+1][j]==0)
			{
				u[++cnt]=find(getid(i+1,j)),v[cnt]=find(getid(i,j+1));
			}
		}
	}
//	for(int i=1;i<=cnt;i++) printf("%d %d\n",u[i],v[i]);
	return count();
}
int solve2()
{
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) fa[getid(i,j)]=getid(i,j);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		if(s[i][j]=='\\'&&col[i][j]==1&&col[i+1][j+1]==1)
		{
			int u=find(getid(i,j)),v=find(getid(i+1,j+1));
			if(u==v) return 0;
			fa[u]=v;
		}
		if(s[i][j]=='/'&&col[i+1][j]==1&&col[i][j+1]==1)
		{
			int u=find(getid(i+1,j)),v=find(getid(i,j+1));
			if(u==v) return 0;
			fa[u]=v;
		}
	}
	C=0; cnt=0;
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++)
	{
		if(col[i][j]==1)
		{
			if(find(getid(i,j))==getid(i,j)) rev[getid(i,j)]=++C;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='*'&&find(getid(i,j))!=find(getid(i+1,j+1))&&col[i][j]==1)
			{
				u[++cnt]=find(getid(i,j)),v[cnt]=find(getid(i+1,j+1));
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='*'&&find(getid(i+1,j))!=find(getid(i,j+1))&&col[i+1][j]==1)
			{
				u[++cnt]=find(getid(i+1,j)),v[cnt]=find(getid(i,j+1));
			}
		}
	}
	return count();
}
signed main()
{
	cin>>n>>m>>mod;
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) col[i][j]=(i+j)&1;
	cout<<add(solve1(),solve2())<<endl;
	return 0;
}