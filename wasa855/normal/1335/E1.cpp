#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
#define N 200005
int sum[205][N],a[N];
vector<int> v[N];
int query(int l,int r)
{
	int ans=0;
	for(int i=1;i<=200;i++) if(sum[i][r]-sum[i][l-1]>ans) ans=sum[i][r]-sum[i][l-1];
	return ans;
}
void work()
{
	int n=read();
	for(int i=1;i<=200;i++) v[i].clear();
	for(int i=1;i<=200;i++) for(int j=1;j<=n;j++) sum[i][j]=0;
	for(int i=1;i<=n;i++) a[i]=read(),v[a[i]].pb(i),sum[a[i]][i]++;
	for(int i=1;i<=200;i++)
	{
		for(int j=1;j<=n;j++) sum[i][j]+=sum[i][j-1];
	}
	int ans=0;
	for(int i=1;i<=200;i++)
	{
		if(sum[i][n]>ans) ans=sum[i][n];
		for(int j=1;j*2<=(int)v[i].size();j++)
		{
			int R=j*2+query(v[i][j-1]+1,v[i][(int)v[i].size()-j]-1);
			if(R>ans) ans=R;
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=read();
	while(T--)  work();
	return 0;
}