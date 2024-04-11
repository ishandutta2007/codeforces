#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 1005
int n;
double p[N][N];
double dis[N];
double sum[N];
bool vis[N];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) p[i][j]=read()/100.0;
	}
	for(int i=1;i<=n;i++) dis[i]=1,sum[i]=1-p[i][n];
	dis[n]=0; vis[n]=1;
	for(int i=1;i<=n;i++)
	{
		int u=0; double v=inf;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&(dis[j]/(1-sum[j]))<v) v=(dis[j]/(1-sum[j])),u=j;
		}
		if(!u) break;
		vis[u]=1;
		dis[u]/=(1-sum[u]);
		for(int j=1;j<=n;j++)
		{
			if(vis[j]) continue;
			dis[j]+=dis[u]*p[j][u]*sum[j];
			sum[j]*=(1-p[j][u]);
		}
	}
	printf("%.7lf\n",dis[1]);
	return 0;
}