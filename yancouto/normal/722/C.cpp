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
const int N = 212345;
int S[N], sz[N], p[N], a[N], ok[N]; ll sum[N], mx;
int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}

void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	S[b] = a;
	sz[a] += sz[b];
	sum[a] += sum[b];
	mx = max(mx, sum[a]);
}

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	for(i = 0; i < n; i++) scanf("%d", &p[i]);
	vector<ll> ans;
	ans.pb(0);
	for(i = 0; i < n; i++) p[i]--, S[i] = i, sz[i] = 1;
	for(i = n - 1; i > 0; i--) {
		sum[p[i]] = a[p[i]];
		mx = max(mx, (ll)a[p[i]]);
		if(p[i] > 0 && ok[p[i] - 1]) join(p[i], p[i] - 1);
		if(p[i] < n && ok[p[i] + 1]) join(p[i], p[i] + 1);
		ok[p[i]] = 1;
		ans.pb(mx);
	}
	while(!ans.empty()) {
		printf("%lld\n", ans.back());
		ans.pop_back();
	}
}