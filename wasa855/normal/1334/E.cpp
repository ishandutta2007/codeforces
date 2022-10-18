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
#define N 1000005
int n,Q;
int fac[N],inv[N];
vector<int> d;
int calc(int x)
{
	int ans=1,sum=0;
	for(int i:d)
	{
		// printf("%d\n",i);
		if(x%i==0)
		{
			int cnt=0;
			while(x%i==0) x/=i,cnt++;
			ans=mul(ans,inv[cnt]); sum+=cnt;
		}
	}
	// printf("%d %d\n",ans,fac[sum]);
	return mul(ans,fac[sum]);
}
signed main()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	for(int i=1;i<N;i++) inv[i]=mul(inv[i-1],inv[i]);
	cin>>n>>Q;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0) d.pb(i);
		while(n%i==0) n/=i;
	}
	if(n!=1) d.pb(n);
	while(Q--)
	{
		int u=read(),v=read();
		int g=__gcd(u,v);
		printf("%lld\n",mul(calc(u/g),calc(v/g)));
	}
	return 0;
}