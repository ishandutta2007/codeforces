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
const db pi = 3.1415926535897932384626;

int n;
double theta, r;

inline void solve(){
	scanf("%d", &n);
	theta = (pi * 2) / (n * 2);
	if(!(n & 1)){
		printf("%.10lf\n", 1.0 / tan(0.5 * theta));
	}
	else{
		db ans = 0;
		r = 0.5 / sin(0.5 * theta);
		REP(i, 0, (n + 1) / 2){
			ans = max(ans, r * (sin(theta * i) + cos(theta * i)) / (0.5 * sqrt(2.0)));
        }
        printf("%.10lf\n", ans);
	}
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}