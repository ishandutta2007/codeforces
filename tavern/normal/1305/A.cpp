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
const int maxn = 105;

int T, n;
int a[maxn];

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		FOR(i, 0, n)
			scanf("%d", a + i);
		sort(a, a + n);
		FOR(i, 0, n)
			printf("%d ", a[i]);
		puts("");
		FOR(i, 0, n)
			scanf("%d", a + i);
		sort(a, a + n);
		FOR(i, 0, n)
			printf("%d ", a[i]);
		puts("");
	}
	return 0;
}