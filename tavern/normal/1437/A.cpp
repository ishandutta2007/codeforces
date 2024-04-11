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

int l, r;

inline void solve(){
	scanf("%d%d", &l, &r);
	puts((r < 2 * l) ? "YES" : "NO");
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}