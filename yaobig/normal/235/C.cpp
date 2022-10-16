#include "bits/stdc++.h"
#define rep(i, a, n) for (auto i = a; i <= (n); ++i)
#define revrep(i, a, n) for (auto i = n; i >= (a); --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
using namespace std;

template<class A, class B> string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string) s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template<class A> string to_string(A v) {
	bool first = 1;
	string res = "{";
	for (const auto &x: v) {
		if (!first) res += ", ";
		first = 0;
		res += to_string(x);
	}
	res += "}";
	return res;
}
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

void debug_out() { cerr << endl; }
template<class H, class... T> void debug_out(H h, T... t) {
	cerr << " " << to_string(h);
	debug_out(t...);
}
#ifndef ONLINE_JUDGE
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
	#define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

/**
 * Author: Yuhao Yao
 * Date: 22-10-11
 * Description: Suffix Automaton. (Using map to store sons makes it 2~3 times slower but it should be fine in most cases.)
 *  $len$ is the length of the longest substring corresponding to the state. 
 *  $fa$ is the father in the prefix tree. Note that fa[i] < i doesn't hold.
 *  root is 0.
 * Usage: Use SAM sam(s) for string $s$ or vector $s$.
 * Time: O(|s|).
 * Status: tested on https://ac.nowcoder.com/acm/contest/884/I, https://ac.nowcoder.com/acm/contest/33188/H, https://codeforces.com/gym/101194/problem/F, https://nanti.jisuanke.com/t/A2018, https://darkbzoj.cc/problem/3238, https://nanti.jisuanke.com/t/A1623, https://www.spoj.com/problems/NSUBSTR/en/, https://codeforces.com/contest/235/problem/C.
 */

template<class T> struct SAM {
	struct node { /// start-hash
		map<int, int> nxt;
		int fa, len;
		int occ, pos; // # of occurrence (as prefix) & endpos.
		node(int fa, int len): fa(fa), len(len) {
			occ = pos = 0;
		}
	};

	T s;
	int n;
	vector<node> t;
	vi at; // at[i] = the state at which the i-th prefix of s is.

	SAM(const T &s): s(s), n(sz(s)), at(n) {
		t.emplace_back(-1, 0);
		int last = 0; // create root.

		auto ins = [&](int i, int c) {
			int now = last;
			t.emplace_back(-1, t[now].len + 1);
			last = sz(t) - 1;
			t[last].occ = 1;
			t[last].pos = i;
			at[i] = last;

			while (now != -1 && t[now].nxt.count(c) == 0) {
				t[now].nxt[c] = last;
				now = t[now].fa;
			}
			if (now == -1) t[last].fa = 0; // root is 0.
			else {
				int p = t[now].nxt[c];
				if (t[p].len == t[now].len + 1) t[last].fa = p;
				else {
					auto tmp = t[p];
					tmp.len = t[now].len + 1;
					tmp.occ = 0; // do not copy occ.
					t.push_back(tmp);
					int np = sz(t) - 1;

					t[last].fa = t[p].fa = np;
					while (now != -1 && t[now].nxt.count(c) && t[now].nxt[c] == p) {
						t[now].nxt[c] = np;
						now = t[now].fa;
					}
				}
			}
		};

		rep(i, 0, n - 1) ins(i, s[i]);
	} /// end-hash

	void calOccurrence() { /// start-hash
		vi sum(n + 1), que(sz(t));
		for (auto &it: t) sum[it.len]++;
		rep(i, 1, n) sum[i] += sum[i - 1];
		rep(i, 0, sz(t) - 1) que[--sum[t[i].len]] = i;
		reverse(all(que));
		for (auto now: que) if (now != 0) t[t[now].fa].occ += t[now].occ;
	} /// end-hash

	vector<vi> ReversedPrefixTree() { /// start-hash
		vector<vi> g(sz(t));
		rep(now, 1, sz(t) - 1) g[t[now].fa].push_back(now);
		rep(now, 0, sz(t) - 1) {
			sort(all(g[now]), [&](int i, int j) {
				return s[t[i].pos - t[now].len] < s[t[j].pos - t[now].len];
			});
		}
		return g;
	} /// end-hash
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s; cin >> s;
	SAM sam(s);
	sam.calOccurrence();
	auto &t = sam.t;

	int n; cin >> n;
	vi mark(sz(t), -1);
	rep(rd, 0, n - 1) {
		string s2; cin >> s2;
		int L = sz(s2);
		s2 += s2;
		int now = 0, len = 0;
		ll ans = 0;
		for (auto c: s2) {
			while (now != -1 && t[now].nxt.count(c) == 0) {
				now = t[now].fa;
				len = now == -1 ? 0 : t[now].len;
			}
			if (now == -1) now = 0;
			else {
				now = t[now].nxt[c];
				len++;
				if (len > L) {
					while (t[now].fa != -1 && t[t[now].fa].len >= L) now = t[now].fa;
					len = L;
				}
				if (len == L && mark[now] != rd) {
					mark[now] = rd;
					ans += t[now].occ;
				}
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}