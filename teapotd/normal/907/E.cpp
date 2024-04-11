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

int V, E;
int edges[24];

int bestM, bestK;

void check(int* graph, int m, int i) {
	bool ok = true;
	rep(v, 0, V) if (graph[v] != (1<<V)-1) ok = false;

	if (ok) {
		int k = __builtin_popcount(m);
		if (k < bestK) {
			bestK = k;
			bestM = m;
		}
		return;
	}

	if (i >= V) return;
	check(graph, m, i+1);

	int copy[24];
	memcpy(copy, graph, 24*sizeof(int));

	rep(e, 0, V) if ((graph[i] >> e) & 1) {
		copy[e] |= graph[i];
	}
	check(copy, m | (1<<i), i+1);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);

	// V = 22;
	// rep(i, 0, V) edges[i] |= (1<<i);
	// rep(i, 1, V) {
	// 	edges[i-1] |= (1<<i);
	// 	edges[i] |= (1<<(i-1));
	// }

	cin >> V >> E;

	rep(i, 0, V) edges[i] |= 1 << i;

	rep(i, 0, E) {
		int a, b; cin >> a >> b; a--; b--;
		edges[a] |= 1 << b;
		edges[b] |= 1 << a;
	}

	bestK = V;
	bestM = (1<<V)-1;
	check(edges, 0, 0);

	cout << bestK << endl;
	rep(i, 0, V) if ((bestM >> i) & 1) cout << i+1 << " ";
	cout << endl;
	return 0;
}