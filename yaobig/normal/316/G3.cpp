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
 * Date: 22-10-14
 * Description: General Suffix Automaton of a given Trie $T$. (Using map to store sons makes it 2~3 times slower but it should be fine in most cases.)
 *  $len$ is the length of the longest substring corresponding to the state. 
 *  $fa$ is the father in the prefix tree. Note that fa[i] < i doesn't hold.
 *  $occ$ should be set manually when building Trie $T$.
 *  root is 0.
 * Usage: Use GSAM sam(T) for Trie $T$, where $T$ is of type $vector<GSAM::node>$.
 * Time: O(|T|).
 * Status: tested on https://www.luogu.com.cn/problem/P6139, https://nanti.jisuanke.com/t/42551.
 **/
 
struct GSAM {
	struct node {
		map<int, int> nxt;
		int fa, len;
		int cnt[11];
		node() { fa = -1; len = 0; memset(cnt, 0, sizeof cnt); }
	};
 
	vector<node> t;
	GSAM(vector<node> &trie) {
		swap(t, trie);
		auto ins = [&](int now, int c) {
			int last = t[now].nxt[c];
			t[last].len = t[now].len + 1;
			now = t[now].fa;
			while (now != -1 && t[now].nxt.count(c) == 0) {
				t[now].nxt[c] = last;
				now = t[now].fa;
			}
			if (now == -1) t[last].fa = 0;
			else {
				int p = t[now].nxt[c];
				if (t[p].len == t[now].len + 1) t[last].fa = p;
				else {
					t.emplace_back();
					int np = sz(t) - 1;
					for (auto [i, v]: t[p].nxt) if (t[v].len > 0) {
						t[np].nxt[i] = v; // use emplace here?
					}
					t[np].fa = t[p].fa;
					t[np].len = t[now].len + 1;
 
					t[last].fa = t[p].fa = np;
					while (now != -1 && t[now].nxt.count(c) && t[now].nxt[c] == p) {
						t[now].nxt[c] = np;
						now = t[now].fa;
					}
				}
			}
		};
 
		vi que{0};
		rep(ind, 0, sz(que) - 1) {
			int now = que[ind];
			vi cs;
			for (auto [c, v]: t[now].nxt) {
				cs.push_back(c);
				que.push_back(v);
			}
			for (auto c: cs) ins(now, c);
		}
	}
};
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	vector<GSAM::node> trie(1);
	vector<string> ss(1); cin >> ss[0];
	int n; cin >> n;
	ss.resize(n + 1);
	vi ls(n + 1), rs(n + 1);
	rep(i, 1, n) cin >> ss[i] >> ls[i] >> rs[i];
	rep(i, 0, n) {
		int now = 0;
		for (auto ch: ss[i]) {
			int c = ch;
			if (trie[now].nxt.count(c) == 0) {
				trie.emplace_back();
				trie[now].nxt[c] = sz(trie) - 1;
			}
			now = trie[now].nxt[c];
			trie[now].cnt[i]++;
		}
	}
	int L = sz(trie);
	GSAM sam(trie);
	auto &t = sam.t;
	int tot = sz(t);
	vi sum(L + 1), que(tot);
	for (auto &it: t) sum[it.len]++;
	rep(i, 1, L) sum[i] += sum[i - 1];
	rep(i, 0, tot - 1) que[--sum[t[i].len]] = i;
	reverse(all(que));
	for (auto now: que) if (now != 0) {
		rep(i, 0, n) t[t[now].fa].cnt[i] += t[now].cnt[i];
	}
	ll ans = 0;
	rep(now, 1, tot - 1) {
		if (t[now].cnt[0] > 0) {
			int ok = 1;
			rep(i, 1, n) if (t[now].cnt[i] < ls[i] || t[now].cnt[i] > rs[i]) ok = 0;
			if (ok) ans += t[now].len - t[t[now].fa].len;
		}
	}
	printf("%lld\n", ans);
	return 0;
}