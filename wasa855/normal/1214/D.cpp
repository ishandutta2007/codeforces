#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define mod 19260817
#define N 1000005
vector<int> a[N];
vector<int> ff[N],fe[N];
char ss[N];
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=m+1;j++)
		{
			a[i].pb(0);
			ff[i].pb(0);
			fe[i].pb(0);
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ss+1);
		for(int j=1;j<=m;j++)
		{
			if(ss[j]=='.') a[i][j]=0;
			else a[i][j]=1;
//			cout<<i<<" "<<j<<endl;
//			if(i==2&&j==2) cout<<"Passed\n";
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==0) ff[i][j]=(ff[i-1][j]+ff[i][j-1])%mod;
			if(i==1&&j==1) ff[i][j]=1;
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			if(a[i][j]==0) fe[i][j]=(fe[i+1][j]+fe[i][j+1])%mod;
			if(i==n&&j==m) fe[i][j]=1;
		}
	}
	if(ff[n][m]==0)
	{
		cout<<"0\n"; return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j==1) continue;
			if(i==n&&j==m) continue;
			if(((ff[i][j]*fe[i][j])%mod)==ff[n][m])
			{
				cout<<"1\n"; return 0;
			}
		}
	}
	cout<<"2\n";
	return 0;
}