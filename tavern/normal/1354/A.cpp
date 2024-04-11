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

ll a, b, c, d;

inline void solve(){
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	if(a <= b)
		printf("%lld\n", b);
	else if(c <= d)
		puts("-1");
	else
		printf("%lld\n", b + (a - b + c - d - 1) / (c - d) * c);
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}