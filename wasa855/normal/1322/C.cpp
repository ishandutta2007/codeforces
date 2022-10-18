#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y,int mod){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y,int mod){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y,int mod){return 1LL*x*y%mod;}
#define N 500005
int B1,mod1,B2,mod2;
int pw1[N],pw2[N];
bool prime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
pii G[N];
int w[N];
void work()
{
	map<pii,int> R;
	int n,m;
	n=read(),m=read();
	for(int i=1;i<=n;i++) G[i]=mp(0,0);
	for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[v].fir=add(G[v].fir,pw1[u],mod1);
		G[v].sec=add(G[v].sec,pw2[u],mod2);
	}
	for(int i=1;i<=n;i++)
	{
		if(G[i].fir==0&&G[i].sec==0) continue;
		R[G[i]]+=w[i];
	}
	int ans=0;
	for(auto i:R) ans=__gcd(ans,i.sec);
	printf("%lld\n",ans);
}
signed main()
{
	mt19937 rng(time(NULL));
	mod1=rng()%500000000,mod2=rng()%500000000;
	while(mod1<100000000) mod1=rng()%500000000;
	while(mod2<100000000) mod2=rng()%500000000;
	while(!prime(mod1)) mod1++;
	while(!prime(mod2)) mod2++;
	B1=rng()%mod1; while(B1==0) B1=rng()%mod1;
	B2=rng()%mod2; while(B2==0) B2=rng()%mod2;
	pw1[0]=pw2[0]=1; for(int i=1;i<N;i++) pw1[i]=mul(pw1[i-1],B1,mod1),pw2[i]=mul(pw2[i-1],B2,mod2);
	int T=read();
	while(T--) work();
	return 0;
}