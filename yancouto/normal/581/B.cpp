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
int a[100009];
int main() {
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int m = 0;
	for(i = n - 1; i >= 0; i--) {
		int x = max(m + 1 - a[i], 0);
		m = max(m, a[i]);
		a[i] = x;
	}
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}