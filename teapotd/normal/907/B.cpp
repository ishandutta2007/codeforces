#include <bits/stdc++.h>
using namespace std;
using namespace rel_ops;

using ll  = int64_t;
using ull = uint64_t;
using ld  = long double;

#define IT iterator
#define mp make_pair

#define rep(i, b, e)  for (int i = (b); i < (e); i++)
#define repd(i, b, e) for (int i = (b); i >= (e); i--)
#define each(a, x)    for (auto& a : (x))
#define all(x)        (x).begin(), (x).end()
#define sz(x)         int((x).size())

string to_string(string s) { return '"'+s+'"'; }

template<class T, class U> string to_string(pair<T, U> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class T> string to_string(T v) {
	string s = "[";
	each(x, v) s += to_string(x) + ", ";
	return s + "]";
}

void xdbg(const char*) { cerr << '\n'; }

template<class T, class ...U> void xdbg(const char* s, T a, U... b) {
	while (*s && *s != ',') cerr << *s++;
	cerr << ": " << to_string(a) << *s; xdbg(s+1, b...);
}

#define STR2(x) #x
#define STR(x)  STR2(x)

#ifdef LOC
#define dbg(...) xdbg("<" STR(__LINE__) "> " #__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#define cerr if(0)cerr
#endif

// ---

string fields[9];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);

	each(f, fields) {
		rep(i, 0, 3) {
			string tmp; cin >> tmp;
			f += tmp;
		}
	}

	int ty, tx; cin >> ty >> tx;
	ty--; tx--;
	ty %= 3; tx %= 3;
	ty *= 3; tx *= 3;

	bool ok = false;

	rep(x, tx, tx+3) {
		rep(y, ty, ty+3) if (fields[y][x] == '.') {
			ok = true;
			fields[y][x] = '!';
		}
	}

	rep(y, 0, 9) {
		rep(x, 0, 9) {
			cout << (ok || fields[y][x] != '.'  ? fields[y][x] : '!');
			if (x > 0 && (x % 3) == 2) cout << ' ';
		}

		cout << endl;
		if (y > 0 && (y % 3) == 2) cout << endl;
	}
	return 0;
}