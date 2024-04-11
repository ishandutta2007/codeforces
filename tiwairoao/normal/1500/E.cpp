#include <bits/stdc++.h>
 
#define fi first
#define se second
#define pr std::make_pair
 
typedef long long ll;
typedef std::pair<int, int> pii;

struct IO_Tp
{
	const static int _I_Buffer_Size = 60 << 20;
	char _I_Buffer[_I_Buffer_Size], *_I_pos = _I_Buffer;
	
	const static int _O_Buffer_Size = 60 << 20;
	//char _O_Buffer[_O_Buffer_Size], *_O_pos = _O_Buffer;
	char *const _O_Buffer = _I_Buffer;
	char *_O_pos = _O_Buffer;
	
	IO_Tp() { fread(_I_Buffer, 1, _I_Buffer_Size, stdin); }
	~IO_Tp() { fwrite(_O_Buffer, 1, _O_pos - _O_Buffer, stdout); }
	
	IO_Tp &operator>>(int &res)
	{
		bool neg = false;
		while (!isdigit(*_I_pos))
			neg = *_I_pos++ == '-';
		res = *_I_pos++ - '0';
		while (isdigit(*_I_pos))
			res = res * 10 + (*_I_pos++ - '0');
		res = neg ? -res : res;
		return *this;
	}
	
	IO_Tp &operator>>(ll &res)
	{
		bool neg = false;
		while (!isdigit(*_I_pos))
			neg = *_I_pos++ == '-';
		res = *_I_pos++ - '0';
		while (isdigit(*_I_pos))
			res = res * 10 + (*_I_pos++ - '0');
		res = neg ? -res : res;
		return *this;
	}
	
	IO_Tp &operator<<(ll n)
	{
		static char _buf[10];
		char* _pos = _buf;
		do
			*_pos++ = '0' + n % 10;
		while (n /= 10);
		while (_pos != _buf)
			*_O_pos++ = *--_pos;
		return *this;
	}
	
	IO_Tp &operator<<(char ch)
	{
		*_O_pos++ = ch;
		return *this;
	}
} IO; // by negiizhao

const int N = 400000;

std::mt19937 gen;
std::uniform_int_distribution<unsigned long long>D;

namespace treap{
	unsigned long long pri[N + 5];
	ll sum[N + 5], sl[N + 5], sr[N + 5], key[N + 5];
	int ch[2][N + 5], siz[N + 5], ncnt;
	
	unsigned long long rnd() {return D(gen);}
	int newnode(ll k) {
		int p = (++ncnt); key[p] = k, ch[0][p] = ch[1][p] = 0;
		pri[p] = rnd(), sum[p] = sl[p] = sr[p] = k, siz[p] = 1;
		return p;
	}
	void pushup(int x) {
		siz[x] = siz[ch[0][x]] + siz[ch[1][x]] + 1;
		sum[x] = sum[ch[0][x]] + sum[ch[1][x]] + key[x];
		sl[x] = sl[ch[0][x]] + sl[ch[1][x]] + (siz[ch[1][x]] + 1) * (key[x] + sum[ch[0][x]]);
		sr[x] = sr[ch[0][x]] + sr[ch[1][x]] + (siz[ch[0][x]] + 1) * (key[x] + sum[ch[1][x]]);
	}
	int build(ll *a, int l, int r) {
		if( l > r ) return 0;
		
		int m = (l + r) >> 1, x = newnode(a[m]);
		ch[0][x] = build(a, l, m - 1);
		ch[1][x] = build(a, m + 1, r);
		pushup(x); return x;
	}
	pii split1(int x, int k) {
		if( !x ) return pr(0, 0);
		if( siz[ch[0][x]] >= k ) {
			pii p = split1(ch[0][x], k);
			ch[0][x] = p.se, pushup(x); return pr(p.fi, x);
		} else {
			pii p = split1(ch[1][x], k - siz[ch[0][x]] - 1);
			ch[1][x] = p.fi, pushup(x); return pr(x, p.se);
		}
	} // first k
	pii split2(int x, int k) {
		if( !x ) return pr(0, 0);
		if( siz[ch[1][x]] >= k ) {
			pii p = split2(ch[1][x], k);
			ch[1][x] = p.fi, pushup(x); return pr(x, p.se);
		} else {
			pii p = split2(ch[0][x], k - siz[ch[1][x]] - 1);
			ch[0][x] = p.se, pushup(x); return pr(p.fi, x);
		}
	} // last k
	int merge(int x, int y) {
		if( !x || !y ) return x + y;
		if( pri[x] < pri[y] ) {
			ch[1][x] = merge(ch[1][x], y);
			pushup(x); return x;
		} else {
			ch[0][y] = merge(x, ch[0][y]);
			pushup(y); return y;
		}
	}
	pii split(int x, ll k) {
		if( !x ) return pr(0, 0);
		if( key[x] > k ) {
			pii p = split(ch[0][x], k);
			ch[0][x] = p.se, pushup(x); return pr(p.fi, x);
		} else {
			pii p = split(ch[1][x], k);
			ch[1][x] = p.fi, pushup(x); return pr(x, p.se);
		}		
	} // <= k, > k
	void insert(int &x, ll k) {
		pii p = split(x, k);
		x = merge(merge(p.fi, newnode(k)), p.se);
	}
	void erase(int &x, ll k) {
		pii p = split(x, k), q = split(p.fi, k - 1);
		x = merge(q.fi, p.se);
	}
	ll sum1(int x, int k) {
		if( !x ) return 0;
		if( siz[ch[0][x]] >= k ) return sum1(ch[0][x], k);
		else return sum1(ch[1][x], k - siz[ch[0][x]] - 1) + sum[ch[0][x]] + key[x];
	}
	ll sum2(int x, int k) {
		if( !x ) return 0;
		if( siz[ch[1][x]] >= k ) return sum2(ch[1][x], k);
		else return sum2(ch[0][x], k - siz[ch[1][x]] - 1) + sum[ch[1][x]] + key[x];
	}
	ll suml(int x, int k) {
		if( !x ) return 0;
		if( siz[ch[0][x]] >= k ) return suml(ch[0][x], k);
		else return suml(ch[1][x], k - siz[ch[0][x]] - 1) + sl[ch[0][x]] +
			(sum[ch[0][x]] + key[x]) * (k - siz[ch[0][x]]);
	}
	ll sumr(int x, int k) {
		if( !x ) return 0;
		if( siz[ch[1][x]] >= k ) return sumr(ch[1][x], k);
		else return sumr(ch[0][x], k - siz[ch[1][x]] - 1) + sr[ch[1][x]] + 
			(sum[ch[1][x]] + key[x]) * (k - siz[ch[1][x]]);
	}
}

int rt;
ll calc(int k) {return treap::suml(rt, k) - treap::sumr(rt, k - 1);}
ll get(int k) {return treap::sum1(rt, k) - treap::sum2(rt, k - 1);}
ll solve() {
	int n = treap::siz[rt], mid = (n + 1) >> 1;
	ll ret = treap::sum[rt] - calc(n);
	
	if( get(mid) >= 0 ) return ret;
	
	int l = 1, r = mid;
	while( l < r ) {
		int m = (l + r + 1) >> 1;
		if( get(m) >= 0 ) l = m;
		else r = m - 1;
	}
	
	int p1 = l, p2 = (n + 1) - l;
	
	return ret + calc(p2 - 1) - calc(p1);
}

ll s[N + 5]; int n, q;
int main() {
	IO >> n >> q; for(int i=1;i<=n;i++) IO >> s[i];
	std::sort(s + 1, s + n + 1), rt = treap::build(s, 1, n);
	IO << solve() << '\n';
	
	for(int i=1,op;i<=q;i++) {
		ll x; IO >> op >> x;
		if( op == 1 ) treap::insert(rt, x);
		else treap::erase(rt, x);
		IO << solve() << '\n';
	}
}