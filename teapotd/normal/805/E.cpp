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

// -----

struct Vert {
	vector<Vert*> edges;
	vector<int*> types;
	bool visited{false};
};

int nVerts, nTypes;
vector<Vert> verts;
vector<int> colors;

void dfs(Vert* v) {
	if (v->visited) return;
	v->visited = true;

	vector<int> used;
	each(t, v->types) if (*t > 0) used.push_back(*t);
	sort(all(used));

	int color = 1, i = 0;

	each(t, v->types) if (*t == 0) {
		while (i < sz(used) && used[i] <= color) {
			if (used[i] == color) color++;
			i++;
		}
		*t = color++;
	}

	each(e, v->edges) dfs(e);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> nVerts >> nTypes;

	verts.resize(nVerts);
	colors.resize(nTypes, 0);

	each(v, verts) {
		int s; cin >> s;
		v.types.resize(s);

		each(t, v.types) {
			int x; cin >> x;
			t = &colors[x-1];
		}
	}

	rep(i, 1, nVerts) {
		int a, b; cin >> a >> b;
		verts[a-1].edges.push_back(&verts[b-1]);
		verts[b-1].edges.push_back(&verts[a-1]);
	}

	dfs(&verts[0]);

	int n = 1;
	each(c, colors) n = max(n, c);

	cout << n << endl;
	each(c, colors) cout << (c > 0 ? c : 1) << " ";
	cout << endl;
	return 0;
}