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
#define N 1005
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int x[N][N],y[N][N];
bool vis[N][N];
char ans[N][N];
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			x[i][j]=read(),y[i][j]=read();
		}
	}
	queue<pii> q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i][j]==i&&y[i][j]==j)
			{
				vis[i][j]=1,ans[i][j]='X';
				q.push(mp(i,j));
				while(!q.empty())
				{
					pii u=q.front(); q.pop();
					for(int k=0;k<4;k++)
					{
						pii v=u;
						v.fir+=dx[k],v.sec+=dy[k];
						if(v.fir>=1&&v.fir<=n&&v.sec>=1&&v.sec<=n&&x[v.fir][v.sec]==i&&y[v.fir][v.sec]==j&&!vis[v.fir][v.sec])
						{
							vis[v.fir][v.sec]=1;
							if(k==0) ans[v.fir][v.sec]='U';
							if(k==1) ans[v.fir][v.sec]='D';
							if(k==2) ans[v.fir][v.sec]='L';
							if(k==3) ans[v.fir][v.sec]='R';
							q.push(v);
						}
					}
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=n&&!vis[i][j]&&!vis[i+1][j]&&x[i][j]==-1&&x[i+1][j]==-1)
			{
				q.push(mp(i,j));
				q.push(mp(i+1,j));
				ans[i][j]='D'; ans[i+1][j]='U';
				vis[i][j]=1; vis[i+1][j]=1;
				while(!q.empty())
				{
					pii u=q.front(); q.pop();
					for(int k=0;k<4;k++)
					{
						pii v=u;
						v.fir+=dx[k],v.sec+=dy[k];
						if(v.fir>=1&&v.fir<=n&&v.sec>=1&&v.sec<=n&&x[v.fir][v.sec]==-1&&y[v.fir][v.sec]==-1&&!vis[v.fir][v.sec])
						{
							vis[v.fir][v.sec]=1;
							if(k==0) ans[v.fir][v.sec]='U';
							if(k==1) ans[v.fir][v.sec]='D';
							if(k==2) ans[v.fir][v.sec]='L';
							if(k==3) ans[v.fir][v.sec]='R';
							q.push(v);
						}
					}
				}
			}
			if(j!=n&&!vis[i][j]&&!vis[i][j+1]&&x[i][j]==-1&&x[i][j+1]==-1)
			{
				q.push(mp(i,j));
				q.push(mp(i,j+1));
				ans[i][j]='R'; ans[i][j+1]='L';
				vis[i][j]=1; vis[i][j+1]=1;
				while(!q.empty())
				{
					pii u=q.front(); q.pop();
					for(int k=0;k<4;k++)
					{
						pii v=u;
						v.fir+=dx[k],v.sec+=dy[k];
						if(v.fir>=1&&v.fir<=n&&v.sec>=1&&v.sec<=n&&x[v.fir][v.sec]==-1&&y[v.fir][v.sec]==-1&&!vis[v.fir][v.sec])
						{
							vis[v.fir][v.sec]=1;
							if(k==0) ans[v.fir][v.sec]='U';
							if(k==1) ans[v.fir][v.sec]='D';
							if(k==2) ans[v.fir][v.sec]='L';
							if(k==3) ans[v.fir][v.sec]='R';
							q.push(v);
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!vis[i][j])
			{
				cout<<"INVALID\n";
				return 0;
			}
		}
	}
	cout<<"VALID\n";
	for(int i=1;i<=n;i++) printf("%s\n",ans[i]+1);
	return 0;
}


//