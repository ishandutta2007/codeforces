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

int en = 1;
int tr[31234567][2];
int ct[31234567];
int a[1123456];

int add(int x) {
	int v = 0;
	for(int i = 29; i >= 0; i--) {
		int b = ((x >> i) & 1);
		if(!tr[v][b]) tr[v][b] = en++;
		v = tr[v][b];
		ct[v]++;
	}
}

int get(int x, int k) {
	int v = 0;
	int tot = 0, i;
	for(i = 29; i >= 0 && (v > 0 || i == 29); i--) {
		if(!tr[v][1] && !tr[v][0]) return tot;
		if((k >> i) & 1) {
			if((x >> i) & 1) {
				tot += ct[tr[v][1]];
				v = tr[v][0];
			} else {
				tot += ct[tr[v][0]];
				v = tr[v][1];
			}
		} else {
			if((x >> i) & 1)
				v = tr[v][1];
			else
				v = tr[v][0];
		}
	}
	if(i < 0) tot += ct[v];
	return tot;
}

int main() {
	int i, n, k;
	scanf("%d %d", &n, &k); k--;
	ll tot = 0;
	add(0);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if(i) a[i] ^= a[i - 1];
		tot += get(a[i], k);
		add(a[i]);
	}
	printf("%I64d\n", ll(ll(n) * ll(n - 1)) / 2ll + ll(n) - tot);
}