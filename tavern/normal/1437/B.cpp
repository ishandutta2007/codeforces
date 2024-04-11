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

const int maxn = 1e5 + 5;

int n;
int f[2];
char s[maxn];

inline void solve(){
	scanf("%d%s", &n, s);
	f[0] = f[1] = 0;
	FOR(i, 1, n)
		f[s[i] - '0'] += (s[i] == s[i - 1]);
	printf("%d\n", max(f[0], f[1]));
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}