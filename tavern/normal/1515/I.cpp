#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (int)(x); i < (int)(y); ++i)
#define REP(i, x, y) for(int i = (int)(x); i <= (int)(y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
#define y0 y2226700
#define y1 y2226701
#define y2 y2226702
typedef double lf;
typedef long double Lf;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 2e5 + 5;
const ll INF = 2e18;
const int logn = 20;

class Diamond{
public:
	int w, v, x, id;
	inline bool operator < (const Diamond &oth){ return MP(-v, w) < MP(-oth.v, oth.w); }
} a[maxn];

inline pll operator + (const pll &p, const pll &q){ return MP(p.fst + q.fst, p.snd + q.snd); }
inline pll &operator += (pll &p, const pll &q){ p = p + q; return p; }
inline pll &operator -= (pll &p, const pll &q){ p = p + MP(-q.fst, -q.snd); return p; }

class SegmentTree{
public:
	static const int siz = 262144;
	
	pll dat[siz << 1], tag[siz << 1];
	
	SegmentTree(){ FOR(i, 0, siz << 1) dat[i] = MP(INF, INF), tag[i] = MP(0, 0); return; }
	
	inline void find(int y, ll tot, int &p, pll &res, int x = 1, int l = 0, int r = siz - 1){
		if(dat[x].fst > tot)
			return;
		int md = l + r >> 1;
		if(l >= y){
			if(l == r){
				p = l, res = dat[x];
				return;
			}
			find(y, tot - tag[x].fst, p, res, x << 1, l, md);
			if(!~p)
				find(y, tot - tag[x].fst, p, res, x << 1 | 1, md + 1, r);
			if(~p)
				res += tag[x];
			return;
		}
		if(y <= md)
			find(y, tot - tag[x].fst, p, res, x << 1, l, md);
		if(!~p)
			find(y, tot - tag[x].fst, p, res, x << 1 | 1, md + 1, r);
		if(~p)
			res += tag[x];
		return;
	}
	
	inline void update(int s, int t, pll k, int x = 1, int l = 0, int r = siz - 1){
		if(l >= s && r <= t){
			dat[x] += k;
			tag[x] += k;
			return;
		}
		int md = l + r >> 1;
		if(s <= md)
			update(s, t, k, x << 1, l, md);
		if(t > md)
			update(s, t, k, x << 1 | 1, md + 1, r);
		dat[x] = min(dat[x << 1], dat[x << 1 | 1]) + tag[x];
		return;
	}
	
	inline void modify(int y, pll k, int x = 1, int l = 0, int r = siz - 1){
		if(l == r){
			if(k.fst > 0)
				dat[x] = tag[x];
			dat[x] += k;
			if(k.fst < 0)
				dat[x] = MP(INF, INF);
			return;
		}
		int md = l + r >> 1;
		if(y <= md)
			modify(y, k, x << 1, l, md);
		else
			modify(y, k, x << 1 | 1, md + 1, r);
		dat[x] = min(dat[x << 1], dat[x << 1 | 1]) + tag[x];
		return;
	}
} seg[logn];

int n, q;

class FenwickTree{
public:
	pll dat[maxn];
	inline void update(int x, pll k){ for(++x; x <= n; x += x & (-x)) dat[x] += k; return; }
	inline pll query(int x){ pll ret = MP(0, 0); for(++x; x; x -= x & (-x)) ret += dat[x]; return ret; }
	inline void query(ll k, ll c, int &p, pll &res){
		for(int i = logn - 1; i >= 0; --i) if(p + (1 << i) <= n && dat[p + (1 << i)].fst <= k){
			p += (1 << i);
			k -= dat[p].fst;
			res += dat[p];
		}
		if(p < n){
			int cnt = min(1ll * a[p].x, (c - res.fst) / a[p].w);
			res += MP(1ll * cnt * a[p].w, 1ll * cnt * a[p].v);
			++p;
		}
		return;
	}
} fen[logn];

inline ll query(ll x){
	int p = 0;
	ll v = 0;
	for(int k = logn - 1; k >= 0; --k) if(x >= (1 << k)){
		if(p == n)
			break;
		pll sum = fen[k].query(p - 1);
		pll res = MP(0, 0);
		int p_ = -1; seg[k].find(p, x + sum.fst, p_, res);
		if(!~p_){
			p_ = 0;
			fen[k].query((x - (1 << k)) + sum.fst, x + sum.fst, p_, res);
		}
		res -= sum;
		x -= res.fst, v += res.snd; 
		p = p_;
	}
	return v;
}

int inv[maxn];

inline void update(int y, int x, int f){
	FOR(k, 0, logn){
		if(a[y].w < (1 << k)){
			seg[k].update(y, n - 1, MP(1ll * a[y].w * x, 1ll * a[y].v * x));
			fen[k].update(y, MP(1ll * a[y].w * x, 1ll * a[y].v * x));
		}
		else if((1 << k) <= a[y].w && a[y].w < (1 << k + 1))
			seg[k].modify(y, MP(f * a[y].w, f * a[y].v));
	}
	return;
}

int main(){
	scanf("%d%d", &n, &q);
	
	FOR(i, 0, n)
		scanf("%d%d%d", &a[i].x, &a[i].w, &a[i].v), a[i].id = i;
	sort(a, a + n);
	FOR(i, 0, n)
		inv[a[i].id] = i;
	FOR(i, 0, n) if(a[i].x)
		update(i, a[i].x, a[i].x == 0 ? 0 : 1);
	
	FOR(i, 0, q){
		int tp; scanf("%d", &tp);
		if(tp < 3){
			int x, y;
			scanf("%d%d", &x, &y);
			--y, y = inv[y];
			if(tp == 2)
				x = -x;
			int f = (a[y].x == 0 ? 1 : 0);
			a[y].x += x;
			f = (a[y].x == 0 ? -1 : f);
			update(y, x, f);
		}
		else{
			ll c; scanf("%lld", &c);
			printf("%lld\n", query(c));
		}
	}
	return 0;
}