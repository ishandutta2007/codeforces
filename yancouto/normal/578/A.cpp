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
	int a, b;
	scanf("%d %d", &a, &b);
	if(a == b) { printf("%d\n", b); return 0; }
	bool ok = false;
	double x = 1/0.;
	double c = a - b;
	if(c > 0) {
		int l = 1, r = (a + b + 2) / 2;
		while(l < r) {
			int m = (l + r + 1) / 2;
			if((c / (2.*m)) >= b) l = m;
			else r = m - 1;
		}
		if(l == r && (c / (2.*l)) >= b) x = c / (2.*l), ok = true;
	}
	c = a + b;
	int l = 1, r = (a + b + 2) / 2;
	while(l < r) {
		int m = (l + r + 1) / 2;
		if((c / (2.*m)) >= b) l = m;
		else r = m - 1;
	}
	if(l == r && (c / (2.*l)) >= b) x = min(x, c/ (2.*l)), ok = true;
	if(ok) printf("%.10f\n", x);
	else puts("-1");
}