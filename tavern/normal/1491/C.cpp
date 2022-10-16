#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
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

const int maxn = 5005;

int n;
int a[maxn], b[maxn];

inline void solve(){
	scanf("%d", &n);
	FOR(i, 0, n)
		scanf("%d", a + i);
	FOR(i, 0, n)
		b[i] = 0;
	FOR(i, 0, n){
		REP(j, i + 2, min(n - 1, i + a[i]))
			++b[j];
	}
	
	ll ans = 0;
	FOR(i, 0, n){
		ans += max(0, a[i] - 1 - b[i]);
		b[i + 1] -= min(a[i] - 1 - b[i], 0);
	}
	printf("%lld\n", ans);
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve()); 
	return 0;
}