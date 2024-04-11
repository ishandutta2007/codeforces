#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

inline int get() {
	char c;
	while(isspace(c = getchar()));
	int x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + (c - '0');
	return x;
}

const int N = 1123;
int S[N], sz[N];
int c[N], ch[N];
int tmp;
//int find(int i, int &sw) {
//	if(S[S[i]] != S[i]) {
//		int s = ch[S[i]];
//		S[i] = find(S[i], s);
//		if(s) c[i] = !c[i], sw = !sw, ch[i] = !ch[i];
//	}
//	return S[i];
//}

//inline int find(int i, int f) {
//	int s = i, c = 0;
//	while(S[s] != s) {
//		s = S[s];
//		if(ch[s]) c = !c;
//	}
//	assert(!ch[s]);
//	if(c) ::c[i] = !::c[i], ch[i] = !ch[i];
//	return S[i] = s;
//}

int find(int i, int f) {
	if(S[S[i]] != S[i]) S[i] = find(S[i], f);
	return S[i];
}

vector<int> V[N];

inline void join(int a, int b) {
	if(sz[a] < sz[b]) swap(a, b);
	S[b] = a;
	assert(!ch[a]);
	sz[a] += sz[b];
	for(int x : V[b]) V[a].pb(x);
}

const int M = 1123456;
int a[M], b[M], w[M], p[M];

int main() {
	srand(time(NULL));
	int i, j, n, m, q, l, r;
	n = get(); m = get(); q = get();
	for(i = 0; i < m; i++) {
		a[i] = get() - 1; b[i] = get() - 1;
		if(rand() & 1) swap(a[i], b[i]);
		w[i] = get();
		p[i] = i;
	}
	sort(p, p + m, [](int i, int j) { return w[i] > w[j]; });
	while(q--) {
		l = get() - 1; r = get() - 1;
		for(i = 0; i < n; i++) S[i] = i, sz[i] = 1, c[i] = -1, ch[i] = 0, V[i].clear(), V[i].pb(i);
		for(j = 0; j < m; j++) {
			i = p[j];
			if(i < l || i > r) continue;
			int a = ::a[i], b = ::b[i];
			int xa = find(a, tmp), xb = find(b, tmp);
			if(c[a] > c[b]) swap(a, b);
			//printf("%d (c %d x %d)  %d (c %d x %d)\n", a+1, c[a], xa, b+1, c[b], xb);
			if(c[b] == -1) c[a] = 0, c[b] = 1, join(xa, xb);
			else if(c[a] == c[b]) {
				if(xa == xb) { printf("%d\n", w[i]); break; }
				if(sz[xa] < sz[xb]) swap(xa, xb);
				for(int id : V[xb]) c[id] = !c[id];
				join(xa, xb);
			} else if(c[a] == -1) c[a] = !c[b], join(xa, xb);
			else if(xa != xb) join(xa, xb);
		}
		if(j == m) puts("-1");
	}
}