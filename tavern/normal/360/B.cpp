#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define PB push_back
#define MP make_pair
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int n, k;
int f[maxn], a[maxn];

class FenwickTree{
private:
	int dat[maxn];
public:
	inline void init(){ memset(dat, 0, sizeof(dat)); }
	inline int query(int x){
		int ret = 0;
		for(++x; x; x -= x & -x)
			ret = max(ret, dat[x]);
		return ret;
	}
	inline void update(int x, int k){
		for(++x; x <= n; x += x & -x)
			dat[x] = max(dat[x], k);
		return;
	}
}fen;

inline bool check(ll w){
	vector<ll> vec;
	vector<pair<ll, int> > ord;
	FOR(i, 0, n)
		vec.PB(a[i] - i * w), ord.PB(MP(a[i] + i * w, i));
	sort(vec.begin(), vec.end());
	sort(ord.begin(), ord.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	fen.init();
	int mx = 0;
	for(int it = n - 1; it >= 0; --it){
		int i = ord[it].snd, l = lower_bound(vec.begin(), vec.end(), a[i] - i * w) - vec.begin();
		f[i] = fen.query(l) + 1;
		fen.update(l, f[i]);
		mx = max(mx, f[i]);
	}
	return mx >= n - k;
}

int main(){
	scanf("%d%d", &n, &k);
	FOR(i, 0, n)
		scanf("%d", a + i);

	ll lb = -1, rb = 1ll << 40;
	for(; lb + 1 < rb; ){
		ll md = lb + rb >> 1;
		if(check(md))
			rb = md;
		else
			lb = md;
	}
	
	printf("%lld\n", rb);
	return 0;
}