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

char s[1000];
int main() {
	int i, j, n, p, q, k;
	scanf("%d %d %d", &n, &p, &q);
	scanf("%s", s);
	for(k = 0; k <= n; k += p)
		if((n - k) % q == 0) {
			int pi = k / p, qi = (n - k) / q;
			printf("%d\n", pi + qi);
			for(i = 0; i < pi; i++) {
				for(j = i * p; j < (i + 1) * p; j++)
					putchar(s[j]);
				putchar('\n');
			}
			for(i = 0; i < qi; i++) {
				for(j = pi * p + i * q; j < pi * p + (i + 1) * q; j++)
					putchar(s[j]);
				putchar('\n');
			}
			return 0;
		}
	puts("-1");
}