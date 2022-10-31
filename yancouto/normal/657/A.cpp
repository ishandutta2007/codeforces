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
	int i, n, d, h;
	scanf("%d %d %d", &n, &d, &h);
	if(d == h && d == n - 1) {
		for(i = 0; i < n - 1; i++)
			printf("%d %d\n", i + 1, i + 2);
		return 0;
	}
	if(d == 1 || (d - h) > h) { puts("-1"); return 0; }
	for(i = 0; i < h; i++)
		printf("%d %d\n", i + 1, i + 2);
	int j = i + 2;
	if(d == h) {
		for(i = j; i <= n; i++)
			printf("%d %d\n", j - 2, i);
	} else {
		printf("%d %d\n", 1, j);
		for(i = 0; i < d - h - 1; i++)
			printf("%d %d\n", i + j, i + j + 1);
		for(; i + j + 1 <= n; i++)
			printf("%d %d\n", 1, i + j + 1);
	}
}