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
int n,m;
int a[105];
int rdstr()
{
	char s[65]; scanf("%s",s+1);
	int res=0;
	for(int i=1;i<=m;i++)
	{
		if(s[i]=='1') res|=(1LL<<(m-i));
	}
	return res;
}
void work()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=rdstr();
	int l=0,r=(1LL<<m)-1,ans,ned=(r-n)/2+1;
	// cout<<ned<<endl;
	while(l<=r)
	{
		int mid=(l+r)/2,cnt=mid+1;
		for(int i=1;i<=n;i++) if(a[i]<=mid)  cnt--;
		// printf("%d %d\n",mid,cnt);
		if(cnt>=ned) ans=mid,r=mid-1;
		else l=mid+1;
	}
	for(int i=1;i<=m;i++)
	{
		if(ans&(1LL<<(m-i))) putchar('1');
		else putchar('0');
	}
	puts("");
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}