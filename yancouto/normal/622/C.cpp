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
const int N = 200009;
int a[N], nx[N];

int main() {
	int i, n, m, x, l, r;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	nx[n - 1] = n;
	for(i = n - 2; i >= 0; i--)
		if(a[i + 1] == a[i]) nx[i] = nx[i + 1];
		else nx[i] = i + 1;
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &l, &r, &x); l--; r--;
		if(a[l] != x) { printf("%d\n", l + 1); continue; }
		if(nx[l] <= r) { printf("%d\n", nx[l] + 1); continue; }
		puts("-1");
	}
}