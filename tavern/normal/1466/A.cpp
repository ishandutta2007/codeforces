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

const int maxn = 55;

int n;
int a[maxn];

inline void solve(){
	scanf("%d", &n);
	FOR(i, 0, n)
		scanf("%d", a + i);
	set<int> s;
	FOR(i, 0, n) FOR(j, i + 1, n)
		s.insert(a[j] - a[i]);
	printf("%d\n", s.size());
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}