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
#	define debug(args...) ((void) 0)
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
int S[N], sz[N], mrk[N];

int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}

void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	S[b] = a;
	sz[a] += sz[b];
	mrk[a] |= mrk[b];
}

int a[N], b[N], w[N], p[N];

int main() {
	int i, j, m;
	rd(n); rd(m);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &w[i]); a[i]--; b[i]--;
		p[i] = i;
	}
	for(i = 0; i < n; i++) S[i] = i, sz[i] = 1;
	sort(p, p + m, [](int i, int j) { return w[i] > w[j];} );
	int tot = 0;
	for(i = 0; i < m; i++) {
		int a = ::a[p[i]], b = ::b[p[i]];
		a = find(a); b = find(b);
		if(a == b && mrk[a]) continue;
		if(a == b) { mrk[a] = 1; tot += w[p[i]]; continue; }
		if(mrk[a] && mrk[b]) continue;
		tot += w[p[i]];
		join(a, b);
	}
	printf("%d\n", tot);
}