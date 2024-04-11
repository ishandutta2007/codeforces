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

struct ev {
	int time, i;
	bool eq;
	bool operator < (ev o) const { return time > o.time; }
};

int p[1123456];

ll brut() {
	int i = 0, d;
	for(i = n; i < 2 * n; i++) p[i] = p[i - n];
	ll mn = LLONG_MAX;
	for(d = 0; d < n; d++) {
		ll cur = 0;
		for(i = 0; i < n; i++)
			cur += abs(i - p[i + d]);
		mn = min(mn, cur);
	}
	return mn;
}

int main() {
	int i, j;
	rd(n);
	int lef = 0, rig = 0;
	ll cur = 0;
	priority_queue<ev> evs;
	for(i = 0; i < n; i++) {
		rd(p[i]); p[i]--;

		cur += abs(p[i] - i);
		if(p[i] > i) {
			lef++;
			evs.push(ev{p[i] - i, i, true});
			//printf("push %d %d %d\n", p[i] - i, i, true);
		} else {
			rig++;
			evs.push(ev{n - i, i, false});
			//printf("push %d %d %d\n", n - i, i, false);
		}
	}
	ll mn = cur;
	int mn_i = 0;
	for(i = 1; i < n; i++) {
		int leff = 0, rigg = 0;
		while(!evs.empty() && evs.top().time == i) {
			ev e = evs.top(); evs.pop();
			//printf("ev %d %d[%d] %d\n", e.time, e.i, p[e.i], e.eq);
			if(e.eq) {
				leff--; rigg++;
				evs.push(ev{i + (n - p[e.i]), e.i, false});
			} else {
				rig--; leff++; // remove temporarily
				cur -= n - 1 - p[e.i];
				cur += p[e.i];
				if(p[e.i] == 0) {
					leff--; rigg++;
				} else {
					evs.push(ev{i + p[e.i], e.i, true});
				}
			}
		}
		// continha
		cur += rig;
		cur -= lef;
		//printf("l, r = (%d, %d)\n", lef, rig);
		//printf("[%d] cur %lld\n", i, cur);
		if(cur < mn) {
			mn = cur;
			mn_i = i;
		}
		lef += leff; rig += rigg;
	}
	printf("%lld %d\n", mn, mn_i);
}