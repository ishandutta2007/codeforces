#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define int long long
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
#define N 100005
struct Node
{
	int opt,id,i,x;
	long double v;
};
Node s[N];
int a[N],vis[N];
int k,n,m;
bool cmp1(Node x,Node y){return x.x>y.x;}
bool cmp2(Node x,Node y){return x.v>y.v;}
bool cmp3(Node x,Node y){return x.opt<y.opt;}
signed main()
{
	cin>>k>>n>>m;
	for(int i=1;i<=k;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		s[i].opt=read(),s[i].i=read(),s[i].x=read();
		s[i].id=i;
		if(s[i].opt==1) s[i].x-=a[s[i].i];
	}
	sort(s+1,s+n+1,cmp1);
	for(int i=1;i<=n;i++)
	{
		if(s[i].opt==1)
		{
			if(vis[s[i].i]) continue;
			vis[s[i].i]=1;
			if(s[i].x>0) s[i].v=(long double)(s[i].x+a[s[i].i])/a[s[i].i],a[s[i].i]+=s[i].x;
		}
		else if(s[i].opt==2)
		{
			s[i].v=(long double)(s[i].x+a[s[i].i])/a[s[i].i];
			a[s[i].i]+=s[i].x;
		}
		else s[i].v=s[i].x;
	}
	sort(s+1,s+n+1,cmp2);
	int ans=0;
	for(int i=1;i<=n;i++) if(s[i].v>1) ans=i;
	ans=min(ans,m);
	cout<<ans<<endl;
	sort(s+1,s+ans+1,cmp3);
	for(int i=1;i<=ans;i++) printf("%lld ",s[i].id);
	return 0;
}