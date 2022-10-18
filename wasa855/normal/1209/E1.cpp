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
#define N 105
int a[10][N];
struct Node
{
	int dat,i,j;
};
Node b[N*10];
int n,m;
bool cmp(Node x,Node y)
{
	return x.dat>y.dat;
}
bool used[N];
int ans;
void dfs(int dep,int id)
{
	if(dep==n+1)
	{
		int res=0;
		for(int i=1;i<=n;i++)
		{
			int tmp=0;
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]>tmp) tmp=a[i][j];
			}
			res+=tmp;
		}
		if(res>ans) ans=res;
		return;
	}
	int now=id;
	while(m>now&&used[b[now].j]==true) now++;
	if(now==m+1)
	{
		dfs(n+1,0);
		return;
	}
	used[b[now].j]=true;
	for(int i=1;i<=n;i++)
	{
		dfs(dep+1,now+1);
		int t=a[n][b[now].j];
		for(int j=n;j>=2;j--)
		{
			a[j][b[now].j]=a[j-1][b[now].j];
		}
		a[1][b[now].j]=t;
	}
	used[b[now].j]=0;
}
void work()
{
	cin>>n>>m;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=read();
			b[(i-1)*m+j].dat=a[i][j];
			b[(i-1)*m+j].i=i,b[(i-1)*m+j].j=j;
		}
	}
	sort(b+1,b+n*m+1,cmp);
	dfs(1,1);
	cout<<ans<<endl;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//swd