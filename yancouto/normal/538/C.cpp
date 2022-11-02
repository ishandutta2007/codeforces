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
int d[100009], h[100009];
bool pos(int i, int m) {
	int ds = abs(h[i-1] - m) + abs(h[i] - m);
	if(ds > (d[i] - d[i-1])) return false;
	return true;
}

int main() {
	int i, n, m;
	scanf("%d %d", &n, &m);
	bool ok = true; int mx = 0;
	for(i = 0; i < m; i++) {
		scanf("%d %d", &d[i], &h[i]);
		mx = max(mx, h[i]);
		if(i == 0 || !ok) continue;
		if(abs(h[i] - h[i-1]) > (d[i] - d[i-1])) { ok = false; continue; }
		int l = max(h[i], h[i-1]), r = 200000009;
		while(l < r) {
			int mid = (l + r + 1) / 2;
			if(pos(i, mid)) l = mid;
			else r = mid - 1;
		}
		mx = max(mx, l);
	}
	if(d[0] > 1) mx = max(mx, h[0] + d[0] - 1);
	if(d[m-1] < n) mx = max(mx, h[m-1] + n - d[m-1]);
	if(!ok) puts("IMPOSSIBLE");
	else printf("%d\n", mx);
}