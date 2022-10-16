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
int vis[maxn];
char s[maxn];

inline void solve(){
	scanf("%s", s);
	n = strlen(s);
	int ans = 0;
	FOR(i, 0, n){
		vis[i] = 0;
		vis[i] |= (i && s[i] == s[i - 1] && !vis[i - 1]);
		vis[i] |= (i > 1 && s[i] == s[i - 2] && !vis[i - 2]);
		ans += vis[i];
	}
	printf("%d\n", ans);
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}