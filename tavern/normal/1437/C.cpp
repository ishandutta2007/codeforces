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

const int maxn = 205;
const int INF = 0x3f3f3f3f;

int n, ans;
int a[maxn];
int f[maxn * 2][maxn];

inline void solve(){
	scanf("%d", &n);
	REP(i, 1, n)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	REP(i, 0, n * 2) REP(j, 0, n)
		f[i][j] = INF;
	ans = INF;
	REP(i, 0, n * 2){
		f[i][0] = 0;
		REP(j, 1, i)
			f[i][j] = min(f[i - 1][j - 1] + abs(i - a[j]), f[i - 1][j]);
		ans = min(ans, f[i][n]);
	}
	printf("%d\n", ans);
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}