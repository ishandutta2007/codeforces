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
#define N 205
int f[N][N],ok[N*N*2];
queue<pii> q;
vector<pii> dx;
int chk(int x,int y) {return ok[x*x+y*y];}
void init()
{
	for(int i=0;i*i<N*N*2;i++) ok[i*i]=1;
	for(int i=0;i<=200;i++) for(int j=0;j<=200;j++)
	{
		if(chk(i,j)) dx.eb(i,j),dx.eb(i,-j),dx.eb(-i,j),dx.eb(-i,-j);
	}
	int sx=100,sy=100;
	memset(f,0x3f,sizeof(f));
	q.emplace(sx,sy); f[sx][sy]=0;
	while(!q.empty())
	{
		auto [x,y]=q.front(); q.pop();
		for(auto [fx,fy]:dx)
		{
			int tx=x+fx,ty=y+fy;
			if(tx>=0&&tx<=200&&ty>=0&&ty<=200)
			{
				if(f[tx][ty]>f[x][y]+1) f[tx][ty]=f[x][y]+1,q.emplace(tx,ty);
			}
		}
	}
}
signed main()
{
	init();
	int T=read();
	while(T--)
	{
		int x=read(),y=read();
		printf("%d\n",f[x+100][y+100]);
	}
	return 0;
}