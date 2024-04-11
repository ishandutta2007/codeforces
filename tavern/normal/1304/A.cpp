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

int main(){
	int T;
	scanf("%d", &T);
	FOR(i, 0, T){
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b);
		if((y - x) % (a + b))
			puts("-1");
		else
			printf("%d\n", (y - x) / (a + b));
	}
	return 0;
}