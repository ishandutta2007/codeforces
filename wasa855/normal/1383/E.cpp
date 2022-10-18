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
#define mod 1000000007
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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 1000005
int f[N],dis[N],pos[N],nxt[N],nd[N];
char s[N];
signed main()
{
	scanf("%s",s+1); int n=strlen(s+1);
	int st=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1') {st=i; break;}
	}
	if(!st) {cout<<n<<endl; return 0;}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0') dis[i]=dis[i-1]+1;
	}
	for(int i=0;i<=n+1;i++) pos[i]=n+1;
	for(int i=n;i>=1;i--)
	{
		nxt[i]=pos[0],nd[i]=pos[dis[i]+1];
		pos[dis[i]]=i;
	}
	f[st]=st;
	for(int i=st;i<=n;i++)
	{
		if(nxt[i]!=n+1) f[nxt[i]]=add(f[nxt[i]],f[i]);
		if(nd[i]!=n+1) f[nd[i]]=add(f[nd[i]],f[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(dis[i]<=dis[n]) ans=add(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}