#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, string> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

vector<pii> T[100009];

char s[1009];
int main() {
	int i, n, m, t, p;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%s %d %d", s, &t, &p);
		T[t-1].pb(pii(p, s));
	}
	for(i = 0; i < m; i++) {
		sort(T[i].begin(), T[i].end(), greater<pii>());
		if(T[i].size() >= 3 && T[i][2].fst == T[i][1].fst) puts("?");
		else printf("%s %s\n", T[i][0].snd.c_str(), T[i][1].snd.c_str());
	}
}