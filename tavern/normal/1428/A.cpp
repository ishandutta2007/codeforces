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
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

ll x_1, y_1, x_2, y_2;

inline void solve(){
	scanf("%lld%lld%lld%lld", &x_1, &y_1, &x_2, &y_2);
	ll res = abs(x_1 - x_2) + abs(y_1 - y_2);
	if((x_1 == x_2) || (y_1 == y_2))
		printf("%lld\n", res);
	else
		printf("%lld\n", res + 2);
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}