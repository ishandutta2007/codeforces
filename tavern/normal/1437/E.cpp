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
typedef double lf;
typedef long double Lf;
typedef pair<int, int> pii;

const int maxn = 1e6 + 5;
const int INF = 2e9;

int n, k, ans;
int a[maxn];
int f[maxn];
vector<int> vec, hs;

class FenwickTree{
public:
	int dat[maxn];
	inline void init(){ FOR(x, 0, maxn) dat[x] = -INF; }
	inline void update(int x, int k){ for(++x; x < maxn; x += x & (-x)) dat[x] = max(dat[x], k); }
	inline int query(int x){ int ret = -INF; for(++x; x; x -= x & (-x)) ret = max(ret, dat[x]); return ret; }
	inline void erase(int x){ for(++x; x < maxn; x += x & (-x)) dat[x] = -INF; }
}fen;

inline void solve(int l, int r){
	f[l] = 1; fen.update(a[l], 1);
	REP(i, l + 1, r){
		f[i] = fen.query(a[i]) + 1;
		fen.update(a[i], f[i]);
//		printf("i = %d f = %d\n", i, f[i]);
	}
//	printf("l = %d r = %d f = %d %d\n", l, r, f[l], f[r]);
	ans += (r - l + 1 - f[r]);
	REP(i, l, r)
		fen.erase(a[i]);
	return;
}

int main(){
	scanf("%d%d", &n, &k);
	REP(i, 1, n)
		scanf("%d", a + i);
		
	a[0] = -INF, a[n + 1] = INF; n += 2;
	FOR(i, 0, n)
		a[i] -= i, hs.PB(a[i]);
	sort(hs.begin(), hs.end());
	hs.erase(unique(hs.begin(), hs.end()), hs.end());
	FOR(i, 0, n)
		a[i] = lower_bound(hs.begin(), hs.end(), a[i]) - hs.begin();
	
	vec.PB(0);
	FOR(i, 0, k){
		int x; scanf("%d", &x);
		vec.PB(x);
	}
	vec.PB(n - 1);
	
	fen.init();
	FOR(i, 0, vec.size() - 1){
		if(a[vec[i]] > a[vec[i + 1]]){
			puts("-1");
			return 0;
		}
		solve(vec[i], vec[i + 1]);
	}
	
	printf("%d\n", ans);
	return 0;
}