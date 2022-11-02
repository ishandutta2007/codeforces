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

const int N = 112345, K = 11;
int S[N], sz[N], L[N], R[N];
int p[N], ip[N], P[K][N], iP[K][N];
int s[N][K];

int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}

void join(int a, int b) {
	debug("join(%d, %d)\n", a, b);
	assert(b != -1);
	assert(find(a) != find(b));
	if((a = find(a)) == (b = find(b))) return;
	S[b] = a;
	sz[a] += sz[b];
	R[a] = R[b];
	debug("%d sz %d L %d R %d\n", a, sz[a], L[a], R[a]);
}

set<int> Se[K];

int main() {
	int i, j;
	int n, k;
	rd(n); rd(k);
	for(i = 0; i < n; i++) {
		for(j = 0; j < k; j++) {
			rd(s[i][j]);
			iP[j][i] = i;
		}
		ip[i] = i;
		S[i] = i; sz[i] = 1;
	}
	sort(ip, ip + n, [](int i, int j) { return s[i][0] > s[j][0]; });
	for(j = 0; j < k; j++)
		sort(iP[j], iP[j] + n, [=,j](int a, int b) { return s[a][j] > s[b][j]; });
	for(i = 0; i < n; i++)
		for(j = 1; j < k; j++)
			P[j][iP[j][i]] = i;
	for(i = 0; i < n; i++) p[ip[i]] = i;
	debug("0 p[0] = %d\n", p[0]);
	printf("1\n");
	Se[0].insert(p[0]);
	for(j = 1; j < k; j++)
		Se[j].insert(P[j][0]);
	int mn = p[0];
	L[0] = -1; R[0] = n;
	for(i = 1; i < n; i++) {
		debug("adding %d p[] = %d\n", i, p[i]);
		int nx = n, pr = -1;
		auto it = Se[0].lower_bound(p[i]);
		if(it != Se[0].end()) nx = ip[*it];
		if(it != Se[0].begin()) pr = ip[*prev(it)];
		Se[0].insert(p[i]);
		if(nx != n && pr != -1 && find(nx) == find(pr)) {
			S[i] = find(nx);
			sz[find(nx)]++;
		} else {
			L[i] = pr;
			if(pr != -1) R[find(pr)] = i;
			R[i] = nx;
			if(nx != n) L[find(nx)] = i;
		}
		for(j = 1; j < k; j++) {
			debug("\n======= FOR J = %d (P[][] = %d)\n", j, P[j][i]);
			vector<int> add;
			auto it = Se[j].lower_bound(P[j][i]);
			nx = n; pr = -1;
			if(it != Se[j].end()) nx = iP[j][*it];
			if(it != Se[j].begin()) pr = iP[j][*prev(it)];
			Se[j].insert(P[j][i]);
			if(pr != -1) debug("%d (p %d) -> %d (p %d)\n", pr, p[pr], i, p[i]);
			if(nx != n) debug("%d (p %d) -> %d (p %d)\n", i, p[i], nx, p[nx]);
			if(pr != -1 && p[pr] > p[i]) {
				while(find(i) != find(pr))
					join(L[find(pr)], pr);
			}
			if(nx != n && p[nx] < p[i]) {
				while(find(i) != find(nx))
					join(L[find(i)], i);
			}
		}
		mn = min(mn, p[i]);
		printf("%d\n", sz[find(ip[mn])]);
		
	}
}