#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define INF 0x3fffffff
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 105
#define M 1000005
int d[N][N];
int p[M];
int ans[M];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%1d",&d[i][j]);
			if(d[i][j]==0) d[i][j]=INF;
		}
		d[i][i]=0;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
	int m=read();
	for(int i=1;i<=m;i++) p[i]=read();
	int cnt=0;
	ans[++cnt]=p[1];
	for(int i=1;i<m;)
	{
		for(int j=min(m,i+n+1);j>i;j--)
		{
			if(d[p[i]][p[j]]==j-i)
			{
				ans[++cnt]=p[j];
				i=j;
				break;
			}
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		printf("%d ",ans[i]);
	}
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}