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
#define ll long long
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 505
char s[N][N],op[N][N];
void work()
{
	int n=read(),m=read();
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) s[i][j]='.';
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) op[i][j]=s[i][j];
	for(int i=1;i<=m;i++) s[1][i]='X';
	for(int i=1;i<=m;i++) if(op[2][i]=='X')
	{
		if(i%3==2) continue;
		s[2][i-1]=s[2][i+1]='X';
		s[1][i]='.';
		if(i%3==0) s[1][i+1]='.';
		else s[1][i-1]='.';
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j%3==2) s[i][j]='X';
		}
	}
	if(m%3==1)
	{
		for(int i=2;i<=n;i++) if(op[i][m]=='X') s[i][m-1]='X';
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++) s[i][1]='X';
	}
	for(int i=1;i<=n;i++) s[i][m+1]=0;
	for(int i=1;i<=n;i++) printf("%s\n",s[i]+1);
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}