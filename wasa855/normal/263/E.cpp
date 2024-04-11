#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
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
#define N 1005
int a[N][N];
int s1[N][N],s2[N][N];
signed main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) a[i][j]=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			s1[i][j]=s1[i-1][j-1]+a[i][j];
		}
	}
	for(int i=n;i>=k;i--)
	{
		for(int j=k;j<=m;j++)
		{
			s1[i][j]-=s1[i-k][j-k];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			s2[i][j]=a[i][j]+s2[i-1][j+1];
		}
	}
	for(int i=n;i>=k;i--)
	{
		for(int j=0;j<=m-k+1;j++)
		{
			s2[i][j]-=s2[i-k][j+k];
		}
	}
	int ans=-5,ax=0,ay=0;
	for(int i=k;i<=n-k+1;i++)
	{
		for(int j=k;j<=m-k+1;j++)
		{
			int R=s2[i+k-1][j]+s2[i-1][j-k]-s1[i+k-1][j-1]-s1[i-1][j+k-1];
			if(R>ans) ans=R,ax=i,ay=j;
		}
	}
	cout<<ax<<" "<<ay<<endl;
	return 0;
}