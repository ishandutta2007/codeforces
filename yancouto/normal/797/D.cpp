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
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n;
const int N = 112345;
int l[N], r[N], v[N], p[N];
set<int> at[N];

void go(int u) {
	if(l[u] != -2) {
		go(l[u]);
		set<int> &s = at[l[u]];
		while(!s.empty() && *s.rbegin() > v[u]) s.erase(*s.rbegin());
		s.swap(at[u]);
	}
	if(r[u] != -2) {
		go(r[u]);
		set<int> &s = at[r[u]];
		while(!s.empty() && *s.begin() < v[u]) s.erase(s.begin());
		if(s.size() > at[u].size()) s.swap(at[u]);
		for(int x : s) at[u].insert(x);
	}
	at[u].insert(v[u]);
	//printf("%d:", u);
	//for(int x : at[u]) printf(" %d", x);
	//putchar('\n');
}

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) p[i] = -1;
	for(i = 0; i < n; i++) {
		rd(v[i]); rd(l[i]); rd(r[i]);
		l[i]--; r[i]--;
		p[l[i]] = p[r[i]] = i;
	}
	for(i = 0; p[i] != -1; i++);
	int root = i;
	go(root);
	int fa = 0;;
	for(i = 0; i < n; i++)
		if(!at[root].count(v[i]))
			fa++;
	printf("%d\n", fa);
}