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

int a[2000009];
int b[1000009];
int main() {
	int i, n, x, j;
	//ld d = 0;
	//for(i = 2; i <= 1000000; i++)
	//	d += 1. / i;
	//printf("%Lf\n", 1000000.*d);
	scanf("%d", &n);
	int mx = 0;
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		a[x] = 1;
		mx = max(mx, x);
	}
	for(i = mx; i >= 1; i--) {
		if(!a[i]) continue;
		b[i] = 1;
		for(j = 2 * i; j <= mx; j += i)
			b[i] = max(b[i], 1 + b[j]);
	}
	int mmx = 0;
	for(i = 0; i <= mx; i++)
		mmx= max(mmx, b[i]);
	printf("%d\n", mmx);
}