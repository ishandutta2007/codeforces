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
int a[200009], n; double b[200009];

double calc(double m) {
	int i;
	double mn, mx, weak;
	mn = mx = b[0] = a[0] - m;
	weak = abs(mn);
	for(i = 1; i < n; i++) {
		b[i] = a[i] - m + b[i - 1];
		weak = max(max(weak, max(abs(b[i] - mn), abs(b[i] - mx))), abs(b[i]));
		mn = min(mn, b[i]);
		mx = max(mx, b[i]);
	}
	return weak;
}

int main() {
	clock_t c = clock();
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	double l = -20000, r = 20000;
	while(true) {
		double cma = calc(l + (r - l) * 1/4.), cmb = calc(l + (r - l) * 3/4.);
		if(cma > cmb) l = l + (r - l) * 1 / 4.;
		else r = l + (r - l) * 3 / 4.;
		if((double(clock() - c) / CLOCKS_PER_SEC) >= 1.9) break;
	}
	printf("%.15f\n", calc((l + r) / 2));
}