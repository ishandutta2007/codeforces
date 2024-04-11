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
const int maxm = 1005;

int n, m;
ll ans = 1;
int a[maxn], cnt[maxm];

int main(){
	scanf("%d%d", &n, &m);
	FOR(i, 0, n){
		scanf("%d", a + i);
		++cnt[a[i] % m];
	}
	FOR(i, 0, m) if(cnt[i] > 1){
		puts("0");
		return 0;
	}
	FOR(i, 0, n) FOR(j, i + 1, n)
		(ans *= abs(a[i] - a[j])) %= m;
	printf("%lld\n", ans);
	return 0;
}