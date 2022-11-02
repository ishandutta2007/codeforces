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

bool state[256];
bool tmp[256];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	int remain = 26;
	bool exces = false;
	int ret = 0;

	while (n--) {
		string mode, word; cin >> mode >> word;

		if (mode[0] == '.') {
			each(c, word) if (!state[c]) {
				state[c] = true;
				remain--;
			}
		} else if (mode[0] == '!') {
			each(c, tmp) c = false;
			each(c, word) tmp[c] = true;

			for (char c = 'a'; c <= 'z'; c++) {
				if (!tmp[c] && !state[c]) {
					state[c] = true;
					remain--;
				}
			}
			if (exces) ret++;
		} else if (mode[0] == '?' && n > 0) {
			if (!state[word[0]]) {
				state[word[0]] = true;
				remain--;
			}
			if (exces) ret++;
		}

		if (remain <= 1) exces = true;
	}

	cout << ret << endl;
	return 0;
}