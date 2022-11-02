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

ll solve(int M, vector<ll> &v2, vector<ll> v3) {
	for(int i = 1; i < v3.size(); i++) v3[i] += v3[i - 1];
	ll best = 0, cur = 0;
	for(int i = 0; i <= v2.size() && i * 2 <= M; i++) {
		int id = min<int>(v3.size(), (M - 2 * i) / 3) - 1;
		if(id == -1) best = max(best, cur);
		else best = max(best, cur + v3[id]);
		if(i < v2.size()) cur += v2[i];
	}
	return best;
}

int n, m;

#define ws asdljasdlkj
vector<ll> ws[5];

int main() {
	int i, j;
	rd(n); rd(m);
	for(i = 0; i < n; i++) {
		int w, c;
		rd(w); rd(c);
		ws[w].pb(c);
	}
	for(i = 1; i <= 3; i++) sort(ws[i].begin(), ws[i].end(), greater<ll>());
	vector<ll> v2 = ws[2];
	for(i = 0; i + 1 < ws[1].size(); i += 2) v2.pb(ws[1][i] + ws[1][i + 1]);
	sort(v2.begin(), v2.end(), greater<ll>());
	ll ans = solve(m, v2, ws[3]);
	if(ws[1].size() > 0) {
		v2 = ws[2];
		for(i = 1; i + 1 < ws[1].size(); i += 2) v2.pb(ws[1][i] + ws[1][i + 1]);
		sort(v2.begin(), v2.end(), greater<ll>());
		ans = max(ans, ws[1][0] + solve(m - 1, v2, ws[3]));
	}
	printf("%lld\n", ans);
}