#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod = 998244353;
//My i/o stream
struct fastio
{
	char s[100000];
	int it, len;
	fastio() {it=len=0;}
	inline char get()
	{
		if (it<len) return s[it++]; it=0;
		len=fread(s, 1, 100000, stdin);
		if (len==0) return EOF; else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while (c==' '||c=='\n') c=get();
		if (it>0) it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0; bool ng=0; char c; c=_buff.get();
	while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
	if (c=='-') ng=1, c=_buff.get();
	while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
	return ng?-r:r;
}
template <class T> inline void putnum(T x)
{
	if (x<0) putchar('-'), x=-x;
	register short a[20]={}, sz=0;
	while (x) a[sz++]=x%10, x/=10;
	if(sz==0) putchar('0');
	for (int i=sz-1; i>=0; i--) putchar('0'+a[i]);
}
inline char getreal() {char c=_buff.get(); while (c<=32) c=_buff.get(); return c;}
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn = 3011;
int n, c;
int a[maxn], ans[maxn];
int cost[maxn][maxn];
int tab[maxn], inv_tab[maxn];
void solve1()
{
	for (int i=1; i<=n; i++)
	{
		int cnt[maxn] = {};
		int prod = 1, tot = 1;
		for (int j=i; j>=1; j--)
		{
			if (a[j]!=a[i])
			{
				tot += cnt[a[j]]==0;
				cnt[a[j]]++;
				if (cnt[a[j]]>1) prod = 1ll*prod*inv_tab[cnt[a[j]]-1]%mod;
				prod = 1ll*prod*tab[cnt[a[j]]]%mod;
			}
			if (tot==c)
			{
				cost[i][j] = prod;
			}
		}
	}
	static int dp[maxn][maxn];
	dp[0][0] = 1; ans[0] = tab[n];
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=i/c; j++)
		{
			ll sum = 0;
			for (int k=i-c; k>=0; k--)
			{
				sum += 1ll*dp[j-1][k]*cost[i][k+1];
				if (k%8==0) sum %= mod;
			}
			dp[j][i] = sum%mod;
			ans[j] = (ans[j]+1ll*dp[j][i]*(tab[n-i]+1))%mod;
		}
	}
	for (int i=0; i<=n; i++)
	{
		ll cur = ans[i]-ans[i+1];
		cur = (cur%mod+mod)%mod;
		puti(cur);
	}
}
void upd(int &x, int v)
{
	x = x+v>=mod?x+v-mod:x+v;
}
void solve2()
{
	static int dp[2][1<<10][maxn];
	int p = 0;
	dp[p][0][0] = 1;
	for (int i=1; i<=n; i++)
	{
		int np = p^1;
		for (int j=0; j<(1<<c); j++) for (int k=0; k<=i/c; k++) dp[np][j][k] = dp[p][j][k];
		for (int j=0; j<(1<<c); j++)
		{
			int nj = j|(1<<a[i]-1);
			bool f = false;
			if (nj==(1<<c)-1) nj = 0, f = true;
			for (int k=0; k<=i/c; k++)
			{
				upd(dp[np][nj][k+f], dp[p][j][k]);
			}
		}
		p = np;
	}
	for (int i=0; i<=n; i++)
	{
		ll ans = 0;
		for (int j=0; j<(1<<c); j++) ans = (ans+dp[p][j][i])%mod;
		if (i==0) ans = (ans+mod-1)%mod;
		puti((ans%mod+mod)%mod);
	}
}
int main()
{
	int pw = 1;
	for (int i=0; i<maxn; i++)
	{
		tab[i] = (pw+mod-1)%mod;
		inv_tab[i] = qpow(tab[i], mod-2);
		pw = 1ll*pw*2%mod;
	}
	getii(n, c);
	for (int i=1; i<=n; i++) geti(a[i]);
	if (c>10) solve1();
	else solve2();
	return 0;
}