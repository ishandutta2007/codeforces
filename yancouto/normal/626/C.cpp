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
int main() {
	int i, j, n, m;
	scanf("%d %d", &n, &m);
	n *= 2; m *= 3;
	for(i = 6; i <= n && i <= m; i += 6)
		if(n + 2 < m + 3) n += 2;
		else m += 3;
	printf("%d\n", max(n, m));
}