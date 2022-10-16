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

const int maxn = 5e5 + 5;
const int logn = 60;
const int INF = 1e9 + 7;

int n;
ll a[maxn];
int f[logn], g[logn][logn];

inline void solve(){
	scanf("%d", &n);
	FOR(x, 0, logn){
		f[x] = 0;
		FOR(y, 0, logn)
			g[x][y] = 0;
	}
	FOR(i, 0, n){
		scanf("%lld", a + i);
		FOR(j, 0, logn) if(a[i] >> j & 1){
			++f[j];
			FOR(k, j, logn) if(a[i] >> k & 1)
				++g[j][k];		
		}
	}
	
	int ans = 0;
	
	FOR(x, 0, logn) FOR(y, 0, logn){
		int res = 1ll * ((1ll << x) % INF) * ((1ll << y) % INF) % INF;
		int g_ = (x <= y ? g[x][y] : g[y][x]);
		res = 1ll * res * f[x] % INF * (((1ll * g_ * n % INF) + (1ll * (f[x] - g_) * f[y] % INF)) % INF) % INF;
		(ans += res) %= INF;
	}
	
	printf("%d\n", ans);
	return; 
}

int main(){
	int T = 0;
	for(scanf("%d", &T); T--; solve()); 
	return 0;
}