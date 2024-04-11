#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

bool on[200];
int main() {
	int i, j, n, k, m, x;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%d", &k);
		for(j = 0; j < k; j++) {
			scanf("%d", &x);
			on[x - 1] = true;
		}
	}
	for(i = 0; i < m && on[i]; i++);
	if(i == m) puts("YES");
	else puts("NO");
}