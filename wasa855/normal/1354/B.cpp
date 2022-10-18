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
#define N 200005
int a[N],nxt[N][4];
char s[N];
void work()
{
	scanf("%s",s+1); int n=strlen(s+1);
	for(int i=1;i<=n;i++) a[i]=s[i]-'0';
	for(int i=1;i<=n+3;i++) for(int j=1;j<=3;j++) nxt[i][j]=0;
	nxt[n+1][1]=nxt[n+1][2]=nxt[n+1][3]=n+1;
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=3;j++)
		{
			if(j==a[i]) nxt[i][j]=i;
			else nxt[i][j]=nxt[i+1][j];
		}
	}
	int ans=inf;
	for(int i=1;i<=n;i++)
	{
		int R=max(nxt[i][1],nxt[i][2],nxt[i][3]);
		if(R!=n+1) ans=min(ans,R-i+1);
	}
	if(ans>n) cout<<"0\n";
	else printf("%d\n",ans);
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}