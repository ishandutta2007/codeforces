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

const ll INF = 1e11 + 7;
const int maxn = 2e5 + 5;

int n, m, p;
ll ans = -INF;
pii a[maxn], b[maxn];
pair<pii, int> c[maxn];

class SegmentTree{
private:
	static const int siz = 1048576;
	inline void pushDown(int x){
		dat[x << 1] += tag[x];
		dat[x << 1 | 1] += tag[x];
		tag[x << 1] += tag[x];
		tag[x << 1 | 1] += tag[x];
		tag[x] = 0;
		return;
	}
public:
	inline int size(){ return siz; }
	ll dat[siz << 1], tag[siz << 1];
	inline void build(int x, int l, int r){
		tag[x] = 0;
		if(l == r){
			dat[x] = -INF;
			return;
		}
		int md = l + r >> 1;
		build(x << 1, l, md);
		build(x << 1 | 1, md + 1, r);
		dat[x] = max(dat[x << 1], dat[x << 1 | 1]);
		return;
	}
	inline void modify(int x, int l, int r, int y, int k){
		if(l == r){
			dat[x] = max(dat[x], 1ll * k);
			return;
		}
		int md = l + r >> 1;
		if(y <= md)
			modify(x << 1, l, md, y, k);
		else
			modify(x << 1 | 1, md + 1, r, y, k);
		dat[x] = max(dat[x << 1], dat[x << 1 | 1]);
		return;
	}
	inline void update(int x, int l, int r, int s, int t, int k){
		if(l >= s && r <= t){
			dat[x] += k;
			tag[x] += k;
			return;
		}
		pushDown(x);
		int md = l + r >> 1;
		if(s <= md)
			update(x << 1, l, md, s, t, k);
		if(t > md)
			update(x << 1 | 1, md + 1, r, s, t, k);
		dat[x] = max(dat[x << 1], dat[x << 1 | 1]);
		return;
	}
	inline ll query(){ return dat[1]; }
}seg;

int main(){
	scanf("%d%d%d", &n, &m, &p);
	FOR(i, 0, n)
		scanf("%d%d", &a[i].fst, &a[i].snd);
	FOR(i, 0, m)
		scanf("%d%d", &b[i].fst, &b[i].snd);
	seg.build(1, 0, seg.size() - 1);
	FOR(i, 0, p)
		scanf("%d%d%d", &c[i].fst.fst, &c[i].fst.snd, &c[i].snd);
	sort(a, a + n);
	sort(b, b + m);
	sort(c, c + p);
	FOR(i, 0, m)
		seg.modify(1, 0, seg.size() - 1, b[i].fst, -b[i].snd);
	for(int i = 0, j = 0; i < n; ++i){
		for(; j < p && c[j].fst.fst < a[i].fst; ++j)
			seg.update(1, 0, seg.size() - 1, c[j].fst.snd + 1, seg.size() - 1, c[j].snd);
		ans = max(ans, seg.query() - a[i].snd);
	}
	printf("%lld\n", ans);
	return 0;
}