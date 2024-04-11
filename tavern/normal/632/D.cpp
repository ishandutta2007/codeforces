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
const int maxn = 1e6 + 5;

int n, m;
int a[maxn];
int l;
int f[maxn], g[maxn];

int main(){
	scanf("%d%d", &n, &m);
	FOR(i, 0, n){
		scanf("%d", a + i);
		if(a[i] <= m)
			++f[a[i]];
	}
	REP(i, 1, m){
		for(int j = i; j <= m; j += i)
			g[j] += f[i];
	}
	l = 1;
	REP(i, 1, m) if(g[i] > g[l])
		l = i;
	printf("%d %d\n", l, g[l]);
	FOR(i, 0, n) if(~l && !(l % a[i]))
		printf("%d ", i + 1);
	puts("");
	return 0;
}