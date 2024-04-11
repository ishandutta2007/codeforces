#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const ull P = 998244353;
const int maxn = 2e5 + 5;

int n, q;
ull Q;
ull pw[maxn];
char s[maxn];

class Hash{
public:
	ull h;
	int len, p, q;
	Hash(){}
	Hash(char c): len(min(1, (int)c)), p(c), q(c), h(c){}
};

inline Hash operator + (const Hash &u, const Hash &v){
	Hash ret;
	if(!u.len && !v.len){
		ret = Hash(0);
	}
	else if(!u.len)
		ret = v;
	else if(!v.len)
		ret = u;
	else{
		if(u.q == '1' && v.p == '1'){
			if(u.len == 1 && v.len == 1){
				ret = Hash(0);
			}
			else if(u.len == 1){
				ret.len = v.len - 1;
				ret.p = '0';
				ret.q = v.q;
				ret.h = (v.h - (ull)'1' * pw[v.len - 1] % INF + INF) % INF;
			}
			else if(v.len == 1){
				ret.len = u.len - 1;
				ret.p = u.p;
				ret.q = '0';
				ret.h = (u.h - ull('1') + INF) % INF * Q % INF;
			}
			else{
				ret.len = u.len + v.len - 2;
				ret.p = u.p;
				ret.q = v.q;
				ret.h = ((u.h - ull('1') + INF) % INF * Q % INF * pw[v.len - 1] % INF + (v.h - ull('1') * pw[v.len - 1] % INF + INF) % INF) % INF;
			}
		}
		else{
			ret.len = u.len + v.len;
			ret.p = u.p;
			ret.q = v.q;
			ret.h = (u.h * pw[v.len] % INF + v.h) % INF;
		}
	}
	return ret;
}

class SegmentTree{
private:
	static const int siz = 262144;
	inline void build(int x, int l, int r){
		if(l == r){
			if(l >= n)
				dat[x] = Hash(0);
			else
				dat[x] = Hash(s[l]);
			return;
		}
		int md = l + r >> 1;
		build(x << 1, l, md);
		build(x << 1 | 1, md + 1, r);
		dat[x] = dat[x << 1] + dat[x << 1 | 1];
		return;
	}
public:
	Hash dat[siz << 1];
	inline int size(){ return siz; }
	inline void init(){
		build(1, 0, siz - 1);
		return;
	}
	inline Hash query(int x, int l, int r, int s, int t){
		if(l >= s && r <= t){
			return dat[x];
		}
		int md = l + r >> 1;
		if(t <= md)
			return query(x << 1, l, md, s, t);
		if(s > md)
			return query(x << 1 | 1, md + 1, r, s, t);
		Hash ls = query(x << 1, l, md, s, t), rs = query(x << 1 | 1, md + 1, r, s, t);
		Hash ret = ls + rs;
		return ret;
	}
}seg;

inline ull qpow(ull x, ull y){
	ull ret = 1;
	for(; y; y >>= 1){
		if(y & 1)
			(ret *= x) %= INF;
		(x *= x) %= INF;
	}
	return ret;
}

int main(){
	pw[0] = 1;
	Q = qpow(P, INF - 2);
	FOR(i, 1, maxn - 1)
		pw[i] = pw[i - 1] * P % INF;
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%d", &q);
	seg.init();
	FOR(i, 0, q){
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		--l; --r;
		Hash hl = seg.query(1, 0, seg.size() - 1, l, l + x - 1);
		Hash hr = seg.query(1, 0, seg.size() - 1, r, r + x - 1);
		puts(hl.h == hr.h ? "YES" : "NO");
	}
	return 0;
}