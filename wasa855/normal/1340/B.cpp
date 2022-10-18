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
#define N 2005
int t[]={119,18,93,91,58,107,111,82,127,123};
int a[N],f[N][N],cnt[N];
int n,k;
int dfs1(int dep,int r)
{
	// printf("%d %d\n",dep,r);
	if(r<0) return 0;
	if(dep==n+1) return f[dep][r]=r==0;
	if(f[dep][r]!=-1) return f[dep][r];
	for(int i=0;i<=9;i++)
	{
		if((a[dep]&t[i])!=a[dep]) continue;
		if(dfs1(dep+1,r-cnt[a[dep]^t[i]])) f[dep][r]=1;
	}
	if(f[dep][r]==1) return 1;
	return f[dep][r]=0;
}
void dfs2(int dep,int r)
{
	if(dep==n+1) return ;
	// printf("%d %d\n",dep,r);
	assert(f[dep][r]);
	for(int i=9;i>=0;i--)
	{
		if((a[dep]&t[i])!=a[dep]) continue;
		if(r>=cnt[a[dep]^t[i]]&&f[dep+1][r-cnt[a[dep]^t[i]]]==1)
		{
			printf("%d",i);
			dfs2(dep+1,r-cnt[a[dep]^t[i]]);
			return ;
		}
	}
	assert(0);
}
signed main()
{
	memset(f,-1,sizeof(f));
	cin>>n>>k;
	for(int i=1;i<=2000;i++) cnt[i]=cnt[i/2]+(i&1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<7;j++)
		{
			int u; scanf("%1d",&u);
			a[i]=a[i]*2+u;
		}
	}
	dfs1(1,k);
	if(f[1][k]) dfs2(1,k);
	else cout<<"-1\n";
	return 0;
}