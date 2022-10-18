#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 1005
int a[N][N];
int r[N],c[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) r[i]=read();
	for(int j=1;j<=m;j++) c[j]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=r[i];j++)
		{
			a[i][j]=1;
		}
		a[i][r[i]+1]=2;
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=c[j];i++)
		{
			if(a[i][j]==2)
			{
				cout<<"0\n";
				return 0;
			}
			a[i][j]=1;
		}
		if(a[c[j]+1][j]==1)
		{
			cout<<"0\n";
			return 0;
		}
		a[c[j]+1][j]=2;
	}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==0)
			{
				ans=ans*2%1000000007;
			}
		}
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}