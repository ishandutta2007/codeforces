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
#define N 200005
int a[3][N];
int n;
int ok;
void dfs(int x,int y)
{
	if(ok) return ;
	if(x==n)
	{
		ok=y;
		return ;
	}
	if(a[y][x+1]==0)
	{
		dfs(x+1,y);
	}
	else if(a[0][x+1]&&a[1][x+1])
	{
		dfs(x+1,!y);
	}
}
void work()
{
	n=read();
	for(int i=0;i<=1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%1d",&a[i][j]);
			if(a[i][j]<=2) a[i][j]=0;
			else a[i][j]=1;
		}
	}
	ok=0;
	dfs(0,0);
	if(ok) cout<<"YES\n";
	else cout<<"NO\n";
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