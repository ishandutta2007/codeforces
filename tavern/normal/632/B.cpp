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
const int maxn = 5e5 + 5;

int n;
int p[maxn];
ll ans = 0;
ll f[maxn], g[maxn];
char s[maxn];

inline ll query(ll *sum, int l, int r){
	return (l > r ? 0 : (!l ? sum[r] : sum[r] - sum[l - 1]));
}

int main(){
	scanf("%d", &n);
	FOR(i, 0, n)
		scanf("%d", p + i);
	scanf("%s", s);
//	FOR(i, 0, n)
//		printf("%c ", s[i]);
//	puts("");
	FOR(i, 0, n)
		f[i] = (i ? f[i - 1] : 0) + (s[i] == 'A') * p[i];
//	FOR(i, 0, n)
//		printf("%lld ", f[i]);
//	puts("");
	FOR(i, 0, n)
		g[i] = (i ? g[i - 1] : 0) + (s[i] == 'B') * p[i];
//	FOR(i, 0, n)
//		printf("%lld ", g[i]);
//	puts("");
	REP(i, 0, n){
//		printf("i = %lld %lld %lld %lld\n", query(f, 0, i - 1), query(g, i, n - 1), query(g, 0, i - 1), query(f, i, n - 1));
		ans = max(ans, query(f, 0, i - 1) + query(g, i, n - 1));
		ans = max(ans, query(g, 0, i - 1) + query(f, i, n - 1));
	}
	printf("%lld\n", ans);
	return 0;
}