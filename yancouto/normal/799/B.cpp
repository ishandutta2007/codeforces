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

const int N = 212345;
int p[N], a[N], b[N];

struct cmp {
	bool operator()(int i, int j) {
		if(p[i] != p[j]) return p[i] < p[j];
		return i < j;
	}
};

int main() {
	int i, j, x, m;
	rd(n);
	set<int, cmp> c[10];
	for(i = 0; i < n; i++) rd(p[i]);
	for(i = 0; i < n; i++) { rd(a[i]); c[a[i]].insert(i); }
	for(i = 0; i < n; i++) { rd(b[i]); c[b[i]].insert(i); }
	rd(m);
	for(i = 0; i < m; i++) {
		rd(x);
		if(c[x].empty()) printf("-1 ");
		else {
			j = *c[x].begin();
			c[a[j]].erase(j);
			c[b[j]].erase(j);
			printf("%d ", p[j]);
		}
	}
	putchar('\n');
}