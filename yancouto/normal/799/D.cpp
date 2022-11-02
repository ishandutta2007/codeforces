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

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n;
const int N = 112345;
int a[N];

map<ll, bool> mp;
bool pd(int A, int B, int i) {
	if(A > B) swap(A, B);
	if(A <= 1 && B <= 1) return true;
	if(i < 0) return false;
	ll id = ll(A) * ll(N) * ll(N) + ll(B) * ll(N) + ll(i);
	if(mp.count(id)) return mp[id];
	bool &r = mp[id];
	r = pd(A, (B + a[i] - 1) / a[i], i - 1);
	if(!r && A > 1) r = pd((A + a[i] - 1) / a[i], B, i - 1);
	return r;
}

int solve(int A, int B) {
	if(A <= 1 && B <= 1) return 0;
	for(int i = 0; i < n; i++)
		if(pd(A, B, i))
			return i + 1;
	return INT_MAX;
}

int main() {
	int a, b, w, h;
	rd(a); rd(b); rd(h); rd(w); rd(n);
	for(int i = 0; i < n; i++) rd(::a[i]);
	//for(int i = 0; i < n; i++) ::a[i] = max(2, (i / 4) + 2);
	sort(::a, ::a + n, greater<int>());
	n = min(n, 50);
	int ans = min(solve((a + w - 1) / w, (b + h - 1) / h), solve((b + w - 1) / w, (a + h - 1) / h));
	if(ans == INT_MAX) puts("-1");
	else printf("%d\n", ans);
}