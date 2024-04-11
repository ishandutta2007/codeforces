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
#define N 3005
vector<int> v[N];
int g[N],f[N][N],sum[N];
int n,m;
void upd(int f[],int s,int v)
{
	for(int i=m-s;i>=0;i--) f[i+s]=max(f[i+s],f[i]+v);
}
void solve(int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<=m;i++) f[l][i]=g[i];
		return ;
	}
	int t[N]; memcpy(t,g,sizeof(t));
	int mid=(l+r)/2;
	for(int j=mid+1;j<=r;j++) upd(g,v[j].size(),sum[j]);
	solve(l,mid);
	memcpy(g,t,sizeof(g));
	for(int j=l;j<=mid;j++) upd(g,v[j].size(),sum[j]);
	solve(mid+1,r);
	memcpy(g,t,sizeof(g));
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int s=read(); v[i].resize(s);
		for(int j=0;j<s;j++) v[i][j]=read(),sum[i]+=v[i][j];
	}
	solve(1,n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int csum=0;
		for(int j=0;j<min((int)v[i].size(),m);j++)
		{
			csum+=v[i][j];
			ans=max(ans,csum+f[i][m-j-1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}