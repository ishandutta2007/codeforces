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
const int N = 200009;
int f[N];

int main() {
	int i, x, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &x); x--;
		f[x] = i;
	}
	ll tot = 0;
	for(i = 1; i < n; i++)
		tot += abs(f[i] - f[i - 1]);
	printf("%I64d\n", tot);
}