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
const int N = 100009;
int x[N], y[N], p[N];

inline int quad(int i) {
	if(x[i] >= 0 && y[i] >= 0) return 0;
	if(x[i] < 0 && y[i] > 0) return 1;
	if(x[i] < 0) return 2;
	return 3;
}

int cross(int i, int j) {
	return x[i] * y[j] - y[i] * x[j];
}

int prod(int i, int j) {
	return x[i] * x[j] + y[i] * y[j];
}

long double ang[N];
bool cmp(int i, int j) {
	return ang[i] < ang[j];
}

const long double pi = acos((long double)-1);

int main() {
	int i, n, k;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]), p[i] = i;
		ang[i] = atan2((long double)x[i], (long double)y[i]);
	}
	if(n == 2) { puts("2 1"); return 0; }
	sort(p, p + n, cmp);
	long double mn = 1/0.; int best;
	for(k = 0; k < n; k++) {
		i = p[k];
		int j = p[(k + 1) % n];
		long double alf = ang[j] - ang[i];
		while(alf < 0) alf += 2 * pi;
		alf = min(alf, 2. * pi - alf);
		if(alf < mn) best = k, mn = alf;
	}
	printf("%d %d\n", p[best] + 1, p[(best + 1) % n] + 1);
}