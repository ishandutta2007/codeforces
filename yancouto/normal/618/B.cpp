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
const int N = 60;
int a[N][N], p[N], seen[N], ct[N];
int main() {
	int n, i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for(int k = 0; k < n - 1; k++) {
		for(i = 0; i < n; i++) {
			if(seen[i]) continue;
			int mn = INT_MAX, mx = INT_MIN;
			for(j = 0; j < n; j++)
				if(!seen[i] && !seen[j] && i != j)
					mn = min(mn, a[i][j]), mx = max(mx, a[i][j]);
			if(mn >= mx) {
				seen[i] = true;
				p[i] = mn;
				break;
			}
		}
	}
	for(i = 0; i < n; i++)
		ct[p[i]] = 1;
	for(i = 0; i < n; i++)
		if(!p[i])
			for(j = 1; j <= n; j++)
				if(!ct[j])
					p[i] = j;
	for(i = 0; i < n; i++) printf("%d ", p[i]);
	putchar('\n');
}