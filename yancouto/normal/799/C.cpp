

#include <bits/stdc++.h>
using namespace std;
#define p first
#define b second
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

const int N = 212345;
int b[N], p[N], tp[N];

int main() {
	int i, j;
	int c, d; char ch;
	rd(n); rd(c); rd(d);
	int has[2] = {c, d};
	int best[2] = {-1, -1};
	int ans = 0;
	vector<pii> v[2];
	for(i = 0; i < n; i++) {
		rd(b[i]); rd(p[i]); scanf(" %c", &ch); tp[i] = (ch == 'D');
		if(p[i] > has[tp[i]]) continue;
		best[tp[i]] = max(best[tp[i]], b[i]);
		v[tp[i]].push_back(pii(p[i], b[i]));
	}
	for(int t = 0; t < 2; t++) {
		sort(v[t].begin(), v[t].end());
		for(i = 0; i < v[t].size(); i++) {
			if(best[!t] != -1) ans = max(ans, v[t][i].b + best[!t]);
			j = int(upper_bound(v[t].begin(), v[t].end(), pii(has[t] - v[t][i].p, INT_MAX)) - v[t].begin()) - 1;
			j = min(j, i - 1);
			if(j > -1 && j < i)
				ans = max(ans, v[t][i].b + v[t][j].b);
			if(i) v[t][i].b = max(v[t][i].b, v[t][i - 1].b);
		}
	}
	printf("%d\n", ans);
}