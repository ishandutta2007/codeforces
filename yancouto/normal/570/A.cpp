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

int a[200], b[200];
int p[200];
int *v;
bool cmp(int i, int j) {
	return v[i] > v[j];
}
int main() {
	int i, j, n, m;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &b[j]);
			p[j] = j;
		}
		v = b;
		stable_sort(p, p + n, cmp);
		a[p[0]]++;
	}
	for(i = 0; i < n; i++) p[i] = i;
	v = a;
	stable_sort(p, p + n, cmp);
	printf("%d\n", p[0] + 1);
	return 0;
}