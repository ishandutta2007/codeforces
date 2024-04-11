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
const int N = 112345;
int x[N], y[N];


int ok(int mx, int prn=0) {
	unordered_set<int> s;
	for(int i = 0; i < n; i++) {
		int x = y[i];
		while(x > mx) x >>= 1;
		while(s.count(x)) x >>= 1;
		if(x == 0) return false;
		s.insert(x);
	}
	if(prn) {
		for(int x : s) printf("%d ", x);
		putchar('\n');
	}
	return true;
}

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &y[i]);
	int l = 1, r = 1000000000;
	while(l < r) {
		int m = (l + r) / 2;
		if(ok(m)) r = m;
		else l = m + 1;
	}
	ok(l, 1);
}