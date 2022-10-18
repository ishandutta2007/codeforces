#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
#define INF 1e18
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 105
int a[N];
int f[N][N][N];
int w[N];
int dfs(int l,int r,int k)
{
	if(l>r) return 0;
	if(l==r) return w[k];
	if(f[l][r][k]) return f[l][r][k];
	f[l][r][k]=w[k]+dfs(l+1,r,1);
	for(int i=l+1;i<=r;i++)
	{
		if(a[l]==a[i])
		{
			f[l][r][k]=max(f[l][r][k],dfs(l+1,i-1,1)+dfs(i,r,k+1));
		}
	}
	return f[l][r][k];
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
	for(int i=1;i<=n;i++) w[i]=read();
	cout<<dfs(1,n,1)<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}