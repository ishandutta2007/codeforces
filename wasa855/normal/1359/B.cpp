#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 1005
char s[N][N];
void work()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	int ans=0; y=min(y,2*x);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(s[i][j]=='.'&&s[i][j+1]=='.')
			{
				s[i][j]=s[i][j+1]='*'; ans+=y;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) if(s[i][j]=='.') ans+=x;
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}