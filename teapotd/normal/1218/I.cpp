#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for(int i=(b); i<(e); i++)
#define each(a,x) for(auto& a : (x))
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

#define tem template<class t,class u,class...w>
#define pri(x,y)tem auto operator<<(t& o, u a)->decltype(x,o) { o << y; return o; }
pri(a.print(),"{";a.print();o<<"}");
pri(a.y,"("<<a.x<<", "<<a.y<<")");
pri(all(a),"[";auto d="";for(auto i : a)(o << d << i, d=", "); o << "]");
void DD(...){}
tem void DD(t s, u a, w... k) {
	int b = 44;
	while (*s && *s != b) {
		b += (*s == 40 ? 50 : *s == 41 ? -50 : 0);
		cerr << *s++;
	}
	cerr << ": " << a << *s++; DD(s, k...);
}
tem vector<t> span(const t* a, u n) { return {a, a+n}; }
#ifdef LOC
#define deb(...) (DD("#, "#__VA_ARGS__, __LINE__, __VA_ARGS__), cerr << endl)
#else
#define deb(...)
#endif
#define DBP(...) void print() { DD(#__VA_ARGS__, __VA_ARGS__); }

bool board[2005][2005];
bool stripe[2005];
int rows[2005], cols[2005];
bool seen1[2005], seen2[2005];
int n;

void nope() {
	cout << -1 << endl;
	exit(0);
}

void dfsCol(int i, int w, bool ret = 1);

void dfsRow(int i, int w, bool ret = 1) {
	if (rows[i] == 2) {
		rows[i] = w;
	} else {
		if (rows[i] != w) nope();
		if (ret) return;
	}

	if (seen1[i]) return;
	seen1[i] = 1;

	rep(j, 0, n) {
		int wanted = board[i][j];
		if (stripe[j]) wanted ^= w;

		if (stripe[i]) {
			dfsCol(j, wanted);
		} else if (wanted) {
			nope();
		}
	}
}

void dfsCol(int i, int w, bool ret) {
	if (cols[i] == 2) {
		cols[i] = w;
	} else {
		if (cols[i] != w) nope();
		if (ret) return;
	}

	if (seen2[i]) return;
	seen2[i] = 1;

	rep(j, 0, n) {
		int wanted = board[j][i];
		if (stripe[j]) wanted ^= w;

		if (stripe[i]) {
			dfsRow(j, wanted);
		} else if (wanted) {
			nope();
		}
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(18);

	cin >> n;

	rep(i, 0, n) {
		string s; cin >> s;
		rep(j, 0, n) board[i][j] = (s[j] == '1');
	}

	rep(i, 0, n) {
		string s; cin >> s;
		rep(j, 0, n) board[i][j] ^= (s[j] == '1');
	}

	string s; cin >> s;
	rep(i, 0, n) stripe[i] = (s[i] == '1');

	rep(i, 0, n) {
		rows[i] = cols[i] = 2;
	}

	vector<Pii> from;

	rep(i, 0, n) rep(j, 0, n) {
		if ((stripe[i] ^ stripe[j]) == 0) continue;

		if (stripe[j]) {
			rows[i] = board[i][j];
			from.pb({i, 0});
		} else if (stripe[i]) {
			cols[j] = board[i][j];
			from.pb({j, 1});
		}
	}

	each(f, from) {
		if (f.y) dfsCol(f.x, cols[f.x], 0);
		else dfsRow(f.x, rows[f.x], 0);
	}

	rep(i, 0, n) {
		if (rows[i] == 2) {
			dfsRow(i, 0);
		}
		if (cols[i] == 2) {
			dfsCol(i, 0);
		}
	}

	vector<Pii> ans;

	rep(i, 0, n) {
		if (rows[i]) ans.pb({i, 0});
		if (cols[i]) ans.pb({i, 1});
	}

	cout << sz(ans) << '\n';
	each(a, ans) {
		cout << (a.y ? "col " : "row ") << a.x << '\n';
	}
}