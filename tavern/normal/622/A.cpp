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

ll n, x;

int main(){
	scanf("%lld", &n);
	for(x = 1; (1 + x) * x / 2 < n; ++x);
	--x;
	printf("%lld\n", n - (1 + x) * x / 2);
	return 0;
}