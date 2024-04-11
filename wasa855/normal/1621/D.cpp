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
#define int long long
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
int a[N][N],n;
vector<int> G[N*N];
struct Node
{
	int x,y,v;
	bool operator < (const Node &x) const {return v>x.v;}
};
int getid(int x,int y) {return (x-1)*n*2+y;}
int dx[]={-1,1,0,0},dy[]={0,0,1,-1};
int dis[N][N];
void work()
{
	n=read();
	for(int i=1;i<=n*2;i++) for(int j=1;j<=n*2;j++) a[i][j]=read();
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans+=a[i][j]+a[i+n][j+n],a[i][j]=a[i+n][j+n]=0;
	for(int i=1;i<=n*2;i++) for(int j=1;j<=n*2;j++) dis[i][j]=INF;
	dis[1][1]=0;
	priority_queue<Node> q;
	q.push((Node){1,1,0});
	while(!q.empty())
	{
		auto [x,y,v]=q.top(); q.pop();
		if(dis[x][y]!=v) continue;
		for(int k=0;k<4;k++)
		{
			int tx=(x+dx[k]+n*2-1)%(n*2)+1,ty=(y+dy[k]+n*2-1)%(n*2)+1;
			// if(tx>=1&&tx<=n*2&&ty>=1&&ty<=n*2)
			{
				if(v+a[tx][ty]<dis[tx][ty]) dis[tx][ty]=v+a[tx][ty],q.push((Node){tx,ty,dis[tx][ty]});
			}
		}
	}
	int A=min({a[1][n+1],a[1][n*2],a[n][n+1],a[n][n*2],a[n+1][1],a[n+1][n],a[n*2][1],a[n*2][n]});
	cout<<ans+A<<endl;
	// cout<<ans+dis[n*2][n*2]<<"\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}