#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 6005
int n,m,Q;
int fa[N*N],del[N][N];
int dx[]={0,1,1,1,-1,-1,-1,0,0};
int dy[]={0,1,-1,0,1,-1,0,1,-1};
int id(int x,int y){return (x-1)*m*2+y;}
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
bool ok(int &x,int &y)
{
	if(y==0) y=m*2;
	if(y==m*2+1) y=1;
	return x>0&&x<=n&&del[x][y];
}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
void erase(int x,int y)
{
	del[x][y]=1;
	for(int i=1;i<=8;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if(ok(tx,ty)) merge(id(x,y),id(tx,ty));
	}
}
signed main()
{
	cin>>n>>m>>Q;
	if(m==1)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m*2;j++) fa[id(i,j)]=id(i,j);
	}
	int ans=0;
	while(Q--)
	{
		int x=read(),y=read();
		if(del[x][y]) continue;
		// cout<<"**"<<Q+1<<endl;
		bool OK=1;
		for(int i=1;i<=8;i++)
		{
			for(int j=1;j<=8;j++)
			{
				int ux=x+dx[i],uy=y+dy[i];
				int vx=x+dx[j],vy=y+m+dy[j];
				if(ok(ux,uy)&&ok(vx,vy))
				{
					// printf("%d %d  %d %d %d %d  %d %d\n",i,j,ux,uy,vx,vy,find(id(ux,uy)),find(id(vx,vy)));
					if(find(id(ux,uy))==find(id(vx,vy))) OK=0;
				}
			}
		}
		if(OK)
		{
			// cout<<"ok\n";
			ans++;
			erase(x,y),erase(x,y+m);
		}
	}
	cout<<ans<<endl;
	return 0;
}