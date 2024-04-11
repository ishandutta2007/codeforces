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
const int maxn = 2e5 + 5;

int n, ans;
int f[maxn][3];
char s[maxn];

inline void solve(){
	scanf("%s", s);
	n = strlen(s);
	REP(i, 0, n) FOR(j, 0, 3)
		f[i][j] = INF;
	ans = INF;
	for(int i = n - 1; i >= 0; --i) REP(j, '1', '3'){
		if(s[i] == j)
			f[i][j - '1'] = i;
		else{
			f[i][j - '1'] = f[i + 1][j - '1'];
		}
	}
	FOR(i, 0, n)
		ans = min(ans, max(f[i][0], max(f[i][1], f[i][2])) - i + 1);
	if(ans > n)
		ans = 0;
	printf("%d\n", ans);
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}