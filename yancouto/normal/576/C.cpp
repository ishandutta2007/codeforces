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
const int MAX = 1000009;
int x[MAX], y[MAX], p[MAX];
bool cmp(int i, int j) {
	int bli = y[i] / 1000, blj = y[j] / 1000;
	if(bli != blj) return bli < blj;
	if(x[i] != x[j]) return (x[i] < x[j]) ^ (bli & 1);
	return y[i] < y[j];
}

int main() {
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]), p[i] = i;
	sort(p, p + n, cmp);
	for(i = 0; i < n; i++)
		printf("%d ", p[i] + 1);
	putchar('\n');
}