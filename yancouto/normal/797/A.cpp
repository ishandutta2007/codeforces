#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;

int main() {
	int i, k;
	scanf("%d %d", &n, &k);
	vector<int> v;
	for(i = 2; i * i <= n; i++) {
		while(!(n % i)) {
			v.pb(i);
			n /= i;
		}
	}
	if(n > 1) v.pb(n);
	while(v.size() > k) {
		int x = v.back(); v.pop_back();
		v.back() *= x;
	}
	if(v.size() < k) puts("-1");
	else {
		for(int x : v) printf("%d ", x);
		putchar('\n');
	}
}