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

char out[7100000]; int np;
inline void fast_print(int u) {
	int ns = 0;
	while(u > 0) {
		out[np + ns++] = '0' + (u % 10);
		u /= 10;
	}
	reverse(out + np, out + np + ns);
	np += ns;
	out[np++] = ' ';
}

int main() {
	int i, j, n;
	scanf("%d", &n);
	deque<int> p;
	for(i = 0; i < n; i++)
		p.pb(i + 1);
	for(i = 2; i <= n; i++) {
		int cur = p.front(); p.pop_front();
		for(j = i - 1; j < n - 1; j += i)
			swap(cur, p[j]);
		p.pb(cur);
	}
	for(i = 0; i < n; i++)
		printf("%d ", p[i]);
	putchar('\n');
}