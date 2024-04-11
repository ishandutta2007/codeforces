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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
inline int mul(int a,int b,int c,int d){return mul(a,b,mul(c,d));}
#define N 4000005
int fac[N],inv[N],pinv[N];
void init()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	pinv[0]=1; for(int i=1;i<N;i++) pinv[i]=mul(pinv[i-1],inv[i]);
}
int C(int x,int y){return x>=y?mul(fac[x],pinv[x-y],pinv[y]):0;}
signed main()
{
	init();
	int n,m; cin>>n>>m;
	int p=1,res=0;
	for(int i=0;i<=n;i++)
	{
		res=add(res,mul(i+1,p,m,inv[n+m-i]));
		p=mul(p,n-i,inv[n+m-i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int R=mul(res,i+m,inv[i],C(n,i));
		if(i&1) ans=add(ans,R);
		else ans=sub(ans,R);
	}
	cout<<ans<<endl;
	return 0;
}