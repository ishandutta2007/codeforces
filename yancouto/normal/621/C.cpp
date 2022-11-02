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
int l[N], r[N];
int main() {
	int i, j, n, p;
	scanf("%d %d", &n, &p);
	for(i = 0; i < n; i++)
		scanf("%d %d", &l[i], &r[i]);
	double tot = 0;
	for(i = 0; i < n; i++) {
		j = i + 1; if(j == n) j = 0;
		double p1 = double(r[i] / p - (l[i] - 1) / p) / (r[i] - l[i] + 1);
		double p2 = double(r[j] / p - (l[j] - 1) / p) / (r[j] - l[j] + 1);
		tot += 2000 * (p1 + p2 - p1 * p2);
	}
	printf("%.10f\n", tot);
}