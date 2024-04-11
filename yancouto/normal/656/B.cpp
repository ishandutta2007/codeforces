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

ll mdc(ll a, ll b) {
	if(b == 0) return a;
	return mdc(b, a % b);
}

int m[20], d[20];
int a[812345];

int main() {
	ll v = 1; int i, j, n;
	for(i = 2; i <= 16; i++)
		v = (v * i) / mdc(i, v);
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &m[i]);
	for(i = 0; i < n; i++) scanf("%d", &d[i]);
	for(i = 0; i < n; i++)
		for(j = d[i]; j < 720720; j += m[i])
			a[j] = 1;
	printf("%.10f\n", accumulate(a, a + 720720, 0) / 720720.);
}