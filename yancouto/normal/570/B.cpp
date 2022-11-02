#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if(n == 1) { puts("1"); return 0; }
	if(m - 1 >= n - m)
		printf("%d\n", m - 1);
	else printf("%d\n", m + 1);
	return 0;
}