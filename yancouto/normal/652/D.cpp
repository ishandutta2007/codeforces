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
const int N = 212345;
int l[N], r[N], b[N], p[N];
int bit[N], ans[N];
int get(int i) {
	int sum = 0;
	for(i += 2; i; i -= (i & -i))
		sum += bit[i];
	return sum;
}
int add(int i, int v) {
	for(i += 2; i < N; i += (i & -i))
		bit[i] += v;
}

int main() {
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &l[i], &r[i]);
		b[i] = r[i];
		p[i] = i;
	}
	sort(p, p + n, [](int i, int j) { return l[i] == l[j]? r[i] < r[j] : l[i] > l[j]; });
	sort(b, b + n);
	for(int j = 0; j < n; j++) {
		i = p[j];
		r[i] = lower_bound(b, b + n, r[i]) - b;
		ans[i] = get(r[i]);
		add(r[i], 1);
	}
	for(i = 0; i < n; i++)
		printf("%d\n", ans[i]);
}