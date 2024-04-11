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

int dv[1000009];
int main() {
	int i, n, j;
	scanf("%d", &n);
	for(i = 2; i <= 1000000; i++) {
		if(dv[i]) continue;
		for(j = i + i; j <= 1000000; j += i)
			dv[j] = 1;
	}
	for(i = 4; i < n; i++) {
		if(dv[i] && dv[n-i]) {
			printf("%d %d\n", i, n-i);
			return 0;
		}
	}
}