//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
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
const int maxn = 4000111;
struct SGT
{
	struct node
	{
		ll mx, lz;
		void addlz(ll L)
		{
			lz += L;
			mx += L;
		}
	}a[maxn];
	#define ls p<<1
	#define rs p<<1|1
	void pushdown(int p)
	{
		if (a[p].lz)
		{
			a[ls].addlz(a[p].lz);
			a[rs].addlz(a[p].lz);
			a[p].lz=0;
		}
	}
	void update(int p)
	{
		a[p].mx = max(a[ls].mx, a[rs].mx);
	}
	void add(int x, int y, ll v, int l, int r, int p)
	{
		if (x<=l&&r<=y)
		{
			a[p].addlz(v);
			return;
		}
		pushdown(p);
		int m=l+r>>1;
		if (x<=m) add(x,y,v,l,m,ls);
		if (m<y) add(x,y,v,m+1,r,rs);
		update(p);
	}
	ll query(int x, int y, int l, int r, int p)
	{
		if (x<=l&&r<=y) return a[p].mx;
		pushdown(p);
		int m=l+r>>1;
		ll ret=-1e18;
		if (x<=m) ret = max(ret, query(x,y,l,m,ls));
		if (m<y) ret = max(ret, query(x,y,m+1,r,rs));
		return ret;
	}
	void build(int l,int r,int p)
	{
		if (l==r)
		{
			a[p].mx = l;
			a[p].lz = 0;
			return;
		}
		int m = l+r>>1;
		build(l, m, ls);
		build(m+1, r, rs);
		update(p);
	}
}sgt;
const int M = 1000111;
int n;
pair<int,int> q[maxn];
ll querysum(int x)
{
	return -sgt.query(x+1, x+1, 1, M, 1)+x+1;
}
int main()
{
	geti(n);
	sgt.build(1,M,1);
	for (int i=1; i<=n; i++)
	{
		char op = getreal();
		int x, y;
		geti(x);
		if (op=='?')
		{
			putsi(querysum(x)+sgt.query(1,x,1,M,1)-x);
		}
		else if(op=='+')
		{
			geti(y);
			q[i] = MP(x, y);
			sgt.add(x+1, M, -y, 1, M, 1);
		}
		else
		{
			sgt.add(q[x].FF+1, M, q[x].SS, 1, M, 1);
		}
	}
    return 0;
}