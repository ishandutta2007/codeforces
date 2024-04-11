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
const int maxn = 3005;

int n, m;
int l[maxn][maxn], r[maxn][maxn];
ll ans = 0;
char s[maxn][maxn];

class FenwickTree{
private:
	int dat[maxn];
	inline ll query(int x){
		int ret = 0;
		for(++x; x; x -= x & (-x))
			ret += dat[x];
		return ret;
	}
public:
	inline void init(){ memset(dat, 0, sizeof(dat)); return; }
	inline void update(int x, int k){
//		printf("x = %d k = %d\n", x, k);
		for(++x; x <= n; x += x & (-x))
			dat[x] += k;
		return;
	}
	inline ll query(int l, int r){
		if(l > r)
			return 0;
		l = max(l, 0);
		r = min(r, n - 1);
//		printf("l = %d r = %d\n", l, r);
		return (l ? (query(r) - query(l - 1)) : query(r));
	}
}fen;

int main(){
	scanf("%d%d", &n, &m);
	FOR(i, 0, n){
		scanf("%s", s[i]);
		FOR(j, 0, m)
			s[i][j] = (s[i][j] == 'z');
	}
	FOR(i, 0, n){
		FOR(j, 0, m)
			l[i][j] = s[i][j] * ((j ? l[i][j - 1] : 0) + 1);
		for(int j = m - 1; j >= 0; --j)
			r[i][j] = s[i][j] * ((j != m - 1 ? r[i][j + 1] : 0) + 1);
	}
/*	FOR(i, 0, n){
		FOR(j, 0, m)
			printf("%d " , l[i][j]);
		puts("");
	}
	FOR(i, 0, m){
		FOR(j, 0, m)
			printf("%d " , r[i][j]);
		puts("");
	}
*/	FOR(it, 0, m){
		/*
		diag <= left
			x - x' + 1 <= r[x]
			x >= x' >= x - r[x] + 1
		diag <= right
			x - x' + 1 <= l[x']
			l[x']  + x' >= x + 1
		*/
		int i = 0, j = it;
		for(; i < n && j >= 0; ){
			vector<pii> vec;
			fen.init();
			int lst = j;
			for(; i < n && j >= 0 && s[i][j]; ++i, --j){
				vec.PB(MP(l[i][j] + i, i));
			}
//			printf("i = %d j = %d\n", i, j);
			sort(vec.begin(), vec.end());
//			FOR(k, 0, vec.size())
//				printf("(%d %d)\n", vec[k].fst, vec[k].snd);
			for(int k = j, l = vec.size() - 1; k <= lst; ++k){
				for(; l >= 0 && vec[l].fst >= it - k + 1; --l)
					fen.update(vec[l].snd, 1);
//				printf("%d %d query %d %d\n", k, it - k, it - k - r[it - k][k] + 1, it - k);
				ans += fen.query(it - k - r[it - k][k] + 1, it - k);
			}
			for(; i < n && j >= 0 && !s[i][j]; ++i, --j);
		}
//		printf("it = %d ans = %lld\n", it, ans);
	}
	FOR(it, 1, n){
		/*
		diag <= left
			x - x' + 1 <= r[x]
			x >= x' >= x - r[x] + 1
		diag <= right
			x - x' + 1 <= l[x']
			l[x']  + x' >= x + 1
		*/
		int i = it, j = m - 1;
		for(; i < n && j >= 0; ){
			vector<pii> vec;
			fen.init();
			int lst = i;
			for(; i < n && s[i][j]; ++i, --j){
				vec.PB(MP(l[i][j] + i, i));
			}
//			printf("i = %d j = %d\n", i, j);
			sort(vec.begin(), vec.end());
//			FOR(k, 0, vec.size())
//				printf("(%d %d)\n", vec[k].fst, vec[k].snd);
			for(int k = i, l = vec.size() - 1; k >= lst; --k){
				for(; l >= 0 && vec[l].fst >= k + 1; --l)
					fen.update(vec[l].snd, 1);
				ans += fen.query(k - r[k][m + it - 1 - k] + 1, k);
			}
			for(; i < n && j >= 0 && !s[i][j]; ++i, --j);
		}
//		printf("it = %d ans = %lld\n", it, ans);
	}
	printf("%lld\n", ans);
	return 0;
}