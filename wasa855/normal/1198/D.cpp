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
#define N 55
char s[N][N],t[N][N];
int f[N][N][N][N];
int dfs(int a,int b,int c,int d)
{
	if(f[a][b][c][d]!=-1) return f[a][b][c][d];
	if(a==c&&b==d) return f[a][b][c][d]=t[a][b];
	f[a][b][c][d]=max(c-a+1,d-b+1);
	for(int i=a;i<c;i++)
	{
		int res=dfs(a,b,i,d)+dfs(i+1,b,c,d);
		if(res<f[a][b][c][d]) f[a][b][c][d]=res;
	}
	for(int i=b;i<d;i++)
	{
		int res=dfs(a,b,c,i)+dfs(a,i+1,c,d);
		if(res<f[a][b][c][d]) f[a][b][c][d]=res;
	}
//	printf("%d %d %d %d %d\n",a,b,c,d,f[a][b][c][d]);
	return f[a][b][c][d];
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i][j]=='#') t[i][j]=1;
			else t[i][j]=0;
		}
	}
	memset(f,-1,sizeof(f));
	cout<<dfs(1,1,n,n)<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}