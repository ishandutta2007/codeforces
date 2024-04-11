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
const int maxn = 1e5 + 5;

int n, m, k;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	if(m <= k){
		puts("1");
		return 0;
	}
	else if(n < m){
		puts("0");
		return 0;
	}
	db ans = 1;
	for(db i = m - k, j = n + 1; i <= m; ++i, ++j)
		(ans *= i) /= j;
	ans = 1 - ans;
	printf("%.10lf\n", ans);
	return 0;
}