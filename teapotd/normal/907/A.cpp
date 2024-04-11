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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	int a, b, c, d; cin >> a >> b >> c >> d;

	int L1 = max(max(a, d), 2*d+1), L2 = 2*a;
	int M1 = max(max(b, d), 2*d+1), M2 = 2*b;
	int S1 = max(c, d), S2 = min(2*c, 2*d);

	while (S1 >= M1) M1++;
	while (M1 >= L1) L1++;

	if (L1 > L2 || M1 > M2 || S1 > S2) {
		cout << "-1\n";
	} else {
		cout << L1 << "\n" << M1 << "\n" << S1 << endl;
	}
	return 0;
}