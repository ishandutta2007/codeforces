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
#define N 105
int L[N][N],R[N][N];
int f[N][N];
int n,m;
int dfs(int l,int r)
{
	if(l>r) return 0;
	if(f[l][r]!=-1) return f[l][r];
	int ans=0;
	for(int i=l;i<=r;i++)
	{
		int res=dfs(l,i-1)+dfs(i+1,r),cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(L[j][i]>=l&&R[j][i]<=r) cnt++;
		}
		// printf("%d %d %d %d\n",l,r,i,cnt);
		ans=max(ans,res+cnt*cnt);
	}
	return f[l][r]=ans;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int k=read();
		while(k--)
		{
			int l=read(),r=read();
			for(int j=l;j<=r;j++) L[i][j]=l,R[i][j]=r;
		}
	}
	memset(f,-1,sizeof(f));
	cout<<dfs(1,m)<<endl;
	return 0;
}