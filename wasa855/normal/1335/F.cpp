#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 1000005
int f[N][25];
bool x[N],y[N];
int col[N];
char s[N];
int n,m,k;
int id(int x,int y)
{
	return (x-1)*m+y;
}
void work()
{
	cin>>n>>m;
	k=n*m;
	for(int i=0;i<=k;i++) x[i]=y[i]=0;
	for(int i=1;i<=k;i++) scanf("%1d",&col[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			if(s[j]=='R') f[id(i,j)][0]=id(i,j+1);
			if(s[j]=='L') f[id(i,j)][0]=id(i,j-1);
			if(s[j]=='U') f[id(i,j)][0]=id(i-1,j);
			if(s[j]=='D') f[id(i,j)][0]=id(i+1,j);
		}
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=k;j++) f[j][i]=f[f[j][i-1]][i-1];
	}
	for(int i=1;i<=k;i++)
	{
		x[f[i][20]]=1;
		if(!col[i]) y[f[i][20]]=1;
	}
	int a=0,b=0;
	for(int i=1;i<=k;i++)
	{
		if(x[i]) a++;
		if(y[i]) b++;
	}
	printf("%d %d\n",a,b);
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}