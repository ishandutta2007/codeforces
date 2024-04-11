#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif

struct no {
	int ct, i;
	bool operator < (no o) const {
		if(ct != o.ct) return ct < o.ct;
		return i > o.i;
	}
};

int ct[5009], a[5009];
int ans[5009];

int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < n; i++) {
		pii mx(-1, -1);
		for(j = i; j < n; j++) {
			ct[a[j]]++;
			pii q(ct[a[j]], -a[j]);
			mx = max(mx, q);
			ans[-mx.snd]++;
		}
		for(j = i; j < n; j++) ct[a[j]]--;
	}
	for(i = 1; i <= n; i++) printf("%d ", ans[i]);
	putchar('\n');
}