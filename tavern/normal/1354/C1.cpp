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

inline void solve(){
	scanf("%d", &n);
	double theta = (pi * 2) / (n * 2);
	if(!(n & 1)){
		printf("%.10lf\n", 1.0 / tan(0.5 * theta));
	}
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}