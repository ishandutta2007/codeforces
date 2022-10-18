#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 1000000007
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
#define N 2005
int a[N][N],ans,f[15][15],cnt[20];
int n,m,k,r[N];
int dfs(int x,int y)
{
	if(y==m+1) x++,y=1;
	if(x==n+1) return 1;
	int cur=f[x-1][y]|f[x][y-1];
	int R=(~cur)&((1<<k)-1);
	if(n-x+m-y+1>r[R]) return 0;
	int ans=0,C=-1;
	for(int i=0;i<k;i++)
	{
		if(a[x][y]==-1||a[x][y]==i)
		{
			if(R&(1<<i))
			{
				cnt[i]++;
				f[x][y]=cur|(1<<i);
				if(cnt[i]==1)
				{
					if(C==-1) C=dfs(x,y+1);
					ans+=C;
				}
				else ans+=dfs(x,y+1);
				cnt[i]--;
				if(ans>mod) ans-=mod;
			}
		}
	}
	return ans;
}
signed main()
{
	cin>>n>>m>>k;
	for(int i=1;i<(1<<k);i++) r[i]=r[i>>1]+(i&1);
	if(n+m-1>k)
	{
		cout<<"0\n";
		return 0;
	}
	bool alz=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) a[i][j]=read()-1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=-1) cnt[a[i][j]]++;
		}
	}
	ans=dfs(1,1);
	cout<<ans<<endl;
	return 0;
}