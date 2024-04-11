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

int main() {
	int i, j, k, x;
	rd(n); rd(k);
	vector<int> v;
	int prev = -1, ct = 0, fst = -1;
	for(i = 0; i < n; i++) {
		rd(x);
		x = (x < 0);
		if(x && ct) v.pb(i - prev - 1);
		if(x && !ct) fst = i;
		if(x) prev = i, ct++;
	}
	if(ct == 0) { puts("0"); return 0; }
	int lst = n - prev - 1;
	k -= ct;
	if(k < 0) { puts("-1"); return 0; }
	int best = INT_MAX;
	sort(v.begin(), v.end());
	int ok = k;
	for(int bm = 0; bm < 2; bm++) {
		k = ok;
		int change = 2 * ct;
		if((bm & 1) && lst <= k) {
			k -= lst;
			change--;
		}
		for(i = 0; i < v.size(); i++)
			if(v[i] <= k) {
				k -= v[i];
				change -= 2;
			}
		best = min(best, change);
	}
	printf("%d\n", best);
}