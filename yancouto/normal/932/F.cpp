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
#	define debug(args...) ((void) 0)
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

typedef ll num; const num eps = 0;
struct line {
	num a, b;
	num operator () (num x) const { return a*x + b; }
	bool operator < (const line & ot) const { return a > ot.a; } // decreasing slope, if function ties, the smallest in this order is chosen
};
struct envelope { // min envelope, the first element is the best at the beggining
	deque<line> qu; num lo, hi; envelope (num a, num b) : lo(a), hi(b) {}
	num inter (line a, line b) { assert(!(b<a)); // first point where b beats (properly) a XXX double
		if (b.a == a.a) return (a.b < b.b)?hi+1:lo;
		return max(min((b.b - a.b - (b.b - a.b<0)*(a.a - b.a - 1))/(a.a - b.a) + 1,hi+1),lo);
		num lo = this->lo; num hi = this->hi + 1;
		while (lo < hi) {
			num md = lo + (hi - lo)/2;
			if (a(md) <= b(md)) lo = md+1;
			else hi = md;
		}
		return lo;
	}
	void push_back (line l) { assert(qu.empty() || !(l < qu.back())); // insert a line that is best at hi or never
		if (!qu.empty() && qu.back()(hi) <= l(hi)) return;
		for (num x; qu.size() && l(x = (qu.size()==1?lo:inter(qu[qu.size()-2],qu.back()))) < qu.back()(x); qu.pop_back()); // XXX double
		qu.push_back(l);
	}
	void push_front (line l) { assert(qu.empty() || !(qu.front() < l)); // insert a line that is best at lo or never
		if (!qu.empty() && qu.front()(lo) < l(lo)) return;
		for (num x; qu.size() && l(x = (qu.size()==1?hi:inter(qu[0],qu[1]))) <= qu.front()(x); qu.pop_front()); // XXX double
		qu.push_front(l);
	}
	line pop_front (num lo) { assert(!qu.empty() && this->lo <= lo + eps); // gets best line at this new lo
		for (this->lo = lo; qu.size() > 1 && qu[0](lo) > qu[1](lo); qu.pop_front());
		return qu.front();
	}
	line pop_back (num hi) { assert(!qu.empty() && this->hi >= hi - eps); // gets best line at this new hi
		for (this->hi = hi; qu.size() > 1 && qu[qu.size()-2](hi) <= qu.back()(hi); qu.pop_back());
		return qu.back();
	}
	line get (num x) { assert(!qu.empty() && lo <= x + eps && x <= hi + eps); // gets best line at x
		return (*lower_bound(qu.begin(),qu.end()-1,qu[0],[x](line & a, const line & o){ return a(x) > (*((&a)+1))(x); }));
	}
};
struct full_envelope {
	int sz = 0;
	vector<envelope> v; full_envelope(envelope c) : v({c}), sz(0) {}
	full_envelope() {}
	void add (line l) {
		sz++;
		envelope nw(v[0].lo,v[0].hi); nw.push_back(l);
		while (v.size() && v.back().qu.size() <= nw.qu.size()) {
			envelope aux(nw.lo,nw.hi); auto jt = nw.qu.begin();
			for (line r : v.back().qu) {
				while (jt != nw.qu.end() && *jt < r) aux.push_back(*(jt++));
				aux.push_back(r);
			}
			while (jt != nw.qu.end()) aux.push_back(*(jt++));
			nw = aux; v.pop_back();
		}
		v.push_back(nw);
	}
	line get (num x) { // you can easily use pop_front and pop_back here
		line b = v.front().get(x);
		for (int i = 1; i < v.size(); i++) {
			line c = v[i].get(x);
			if (c(x)!=b(x)?c(x)<b(x):c<b) b = c;
		}
		return b;
	}
};

inline void swp(full_envelope &a, full_envelope &b) {
	a.v.swap(b.v);
	swap(a.sz, b.sz);
}


const int N = 112345;
ll a[N], b[N];
ll dp[N];
full_envelope e[N];
int sz[N];
vector<int> adj[N];

int n;

int go(int u, int p) {
	e[u] = full_envelope(envelope(-2e5, 2e5));
	sz[u] = 0;
	for(int v : adj[u]) {
		if(v == p) continue;
		int s = go(v, u);
		if(s > sz[u])
			swp(e[u], e[v]);
		for(envelope &ev : e[v].v)
			for(line &l : ev.qu)
				e[u].add(l);
		e[v].v.clear();
		sz[u] += s;
	}
	if(e[u].sz == 0)
		dp[u] = 0;
	else
		dp[u] = e[u].get(a[u])(a[u]);
	e[u].add(line{b[u], dp[u]});
	return ++sz[u];
}


int main() {
	int i;
	rd(n);
	for(i = 0; i < n; i++)
		rd(a[i]);
	for(i = 0; i < n; i++)
		rd(b[i]);
	for(i = 0; i < n - 1; i++) {
		int a, b;
		rd(a); rd(b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	go(0, 0);
	for(i = 0; i < n; i++)
		printf("%lld ", dp[i]);
	putchar('\n');
}