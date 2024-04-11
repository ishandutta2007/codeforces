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

namespace sf {
const int NS = 1;
const int N = 212345 * 2;

int cn, cd, ns, en = 1, lst;
string S[NS]; int si = -1;
/* sufn[si][i] no do sufixo S[si][i...] */
vector<int> sufn[N];

struct node {
	int l, r, si;
	int p, suf;
	bool bad = false;
	map<char, int> adj;
	node() : l(0), r(-1), suf(0), p(0) {}
	node(int L, int R, int S, int P) : l(L), r(R), si(S), p(P) {}
	inline int len() { return r - l + 1; }
	inline int operator[](int i) { return S[si][l + i]; }
	inline int& operator()(char c) { return adj[c]; }
} t[N];

inline int new_node(int L, int R, int S, int P) {
	t[en] = node(L, R, S, P);
	return en++;
}

void add_string(string s) {
	s += '$';
	S[++si] = s;
	sufn[si].resize(s.size() + 1);
	cn = cd = 0;
	int i = 0; const int n = s.size();
	for(int j = 0; j < n; j++)
		for(; i <= j; i++) {
			if(cd == t[cn].len() && t[cn](s[j]))
				cn = t[cn](s[j]), cd = 0;
			if(cd < t[cn].len() && t[cn][cd] == s[j]) {
				cd++;
				if(j < s.size() - 1) break;
				else {
					if(i) t[lst].suf = cn;
					for(; i <= j; i++) {
						sufn[si][i] = cn;
						cn = t[cn].suf;
					}
				}
			} else if(cd == t[cn].len()) {
				sufn[si][i] = en;
				if(i) t[lst].suf = en; lst = en;
				t[cn](s[j]) = new_node(j, n - 1, si, cn);
				cn = t[cn].suf;
				cd = t[cn].len();
			} else {
				int mid = new_node(t[cn].l, t[cn].l + cd - 1, t[cn].si, t[cn].p);
				t[t[cn].p](t[cn][0]) = mid;
				if(ns) t[ns].suf = mid;
				if(i) t[lst].suf = en; lst = en;
				sufn[si][i] = en;
				t[mid](s[j]) = new_node(j, n - 1, si, mid);
				t[mid](t[cn][cd]) = cn;
				t[cn].p = mid; t[cn].l += cd;
				cn = t[mid].p;
				int g = cn? j - cd : i + 1;
				cn = t[cn].suf;
				while(g < j && g + t[t[cn](S[si][g])].len() <= j)
					cn = t[cn](S[si][g]), g += t[cn].len();
				if(g == j)
					ns = 0, t[mid].suf = cn, cd = t[cn].len();
				else
					ns = mid, cn = t[cn](S[si][g]), cd = j - g;
			}
		}
}
};

int n;

char s[212345], t[212345];

ll best = 0;

ll go(int u, ll d) {
	sf::node &nu = sf::t[u];
	if(nu.adj.empty()) {
		if(nu.bad) return 0;
		d--;
		best = max(best, d);
		return 1;
	}
	ll sum = 0;
	for(auto e : nu.adj)
		sum += go(e.second, d + sf::t[e.second].len());
	best = max(best, d * sum);
	return sum;
}

int main() {
	int i, j;
	scanf("%d %s %s", &n, s, t);
	reverse(s, s + n);
	reverse(t, t + n);
	sf::add_string(s);
	for(i = 0; i < n; i++)
		if(t[i] == '1')
			sf::t[sf::sufn[0][i]].bad = true;
	go(0, 0);
	printf("%lld\n", best);
}