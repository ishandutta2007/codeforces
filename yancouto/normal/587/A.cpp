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

int p[2000009];
int main() {
	int i, j, n, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		p[x]++;
	}
	int tot = 0;
	for(x = 0; x < 2000009; x++) {
		if(p[x] > 1) p[x + 1] += p[x] / 2;
		p[x] = p[x] & 1;
		tot += p[x];
	}
	printf("%d\n", tot);
}