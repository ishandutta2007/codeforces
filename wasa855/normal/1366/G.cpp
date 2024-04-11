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
#define N 10005
char s[N],t[N];
int f[N][N];
signed main()
{
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=min(i,m);j++)
		{
			f[i+1][j]=min(f[i+1][j],f[i][j]+1);
			if(s[i+1]=='.'&&j) f[i+1][j-1]=min(f[i+1][j-1],f[i][j]);
			if(s[i+1]!='.'&&s[i+1]==t[j+1]) f[i+1][j+1]=min(f[i+1][j+1],f[i][j]);
		}
		int v=-1,cur=0;
		if(s[i+1]=='.') continue;
		for(int j=i+1;j<=n;j++)
		{
			if(s[j]=='.') cur--;
			else cur++;
			if(cur==0) {v=j; break;}
		}
		if(cur!=0) continue;
		// printf("-- %d %d\n",i,v);
		for(int j=0;j<=min(i,m);j++) f[v][j]=min(f[v][j],f[i][j]);
	}
	// for(int i=1;i<=n;i++)
	// {
		// for(int j=1;j<=m;j++) printf("%d ",f[i][j]); cout<<"\n";
	// }
	cout<<f[n][m]<<endl;
	return 0;
}