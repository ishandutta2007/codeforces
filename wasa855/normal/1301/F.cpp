#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
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
int d[N][N][45];
bool vis[45];
vector<pii> C[45];
int a[N][N];
int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,1,-1};
int n,m,c;
struct Node
{
	int x,y,col,d;
};
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=read();
			C[a[i][j]].pb(mp(i,j));
		}
	}
	for(int i=1;i<=c;i++)
	{
//		cout<<i<<endl;
		queue<Node> q;
		for(int j=1;j<=c;j++) vis[j]=0;
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				d[j][k][i]=-1;
				if(a[j][k]==i)
				{
					d[j][k][i]=0;
					q.push((Node){j,k,i,0});
					cnt++;
				}
			}
		}
		while(!q.empty())
		{
			Node u=q.front();
			q.pop();
			if(!vis[a[u.x][u.y]])
			{
				vis[a[u.x][u.y]]=1;
				for(pii v:C[a[u.x][u.y]])
				{
					int tx=v.fir,ty=v.sec;
					if(d[tx][ty][i]!=-1) continue;
					d[tx][ty][i]=u.d+1;
					q.push((Node){tx,ty,i,d[tx][ty][i]});
					cnt++;
				}
			}
			for(int j=1;j<=4;j++)
			{
				int tx=u.x+dx[j],ty=u.y+dy[j];
				if(tx<=0||ty<=0||tx>n||ty>m) continue;
				if(d[tx][ty][i]!=-1) continue;
				d[tx][ty][i]=u.d+1;
				q.push((Node){tx,ty,i,d[tx][ty][i]});
				cnt++;
			}
			if(cnt==n*m) break;
		}
//		cout<<cnt<<endl;
	}
//	cout<<clock()<<endl;
	int Q=read();
	while(Q--)
	{
		int r1=read(),c1=read(),r2=read(),c2=read();
		int ans=abs(r1-r2)+abs(c1-c2);
		for(int i=1;i<=c;i++)
		{
			int R=d[r1][c1][i]+d[r2][c2][i]+1;
			if(R<ans) ans=R;
		}
		printf("%d\n",ans);
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}