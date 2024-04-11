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

vector<char> rein[1123456];
int main() {
	int i, j, q, t, k, d;
	rd(n); rd(q);
	set<int> s;
	for(i = 1; i <= n; i++) s.insert(i);
	int cur = 0;
	for(i = 0; i < q; i++) {
		rd(t); rd(k); rd(d);
		for(; cur <= t; cur++) {
			for(int x : rein[cur]) s.insert(x);
			rein[cur].clear();
		}
		if(s.size() < k) { puts("-1"); continue; }
		int sum = 0;
		while(k) {
			int x = *s.begin();
			sum += x;
			rein[t + d].pb(x);
			s.erase(s.begin());
			k--;
		}
		printf("%d\n", sum);
	}
}