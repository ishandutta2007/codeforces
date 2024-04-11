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

int adj[100];

void tf(ll A[], int l, int r) {
	if(l == r) return;
	int m = (l + r) / 2;
	tf(A, l, m);
	tf(A, m + 1, r);
	for(int i = m + 1; i <= r; i++)
		A[i] = mod(A[i] + A[l + (i - (m + 1))]);
}
int on;

void itf(ll A[], int l, int r) {
	if(l == r) return;
	int m = (l + r) / 2;
	for(int i = m + 1; i <= r; i++) {
		//if(i == (1 << on) - 1) printf("[%d]--= %lld\n", l + (i - (m + 1)), A[l + (i - (m + 1))]);
		A[i] = mod(A[i] - A[l + (i - (m + 1))] + modn);
	}
	itf(A, l, m);
	itf(A, m + 1, r);
}

int last(ll A[], int l, int r) {
	if(l == r) return A[l];
	int m = (l + r) / 2;
	//printf("[%d]-= %lld\n", m, A[m]);
	for(int i = m + 1; i <= r; i++) {
		//if(i == (1 << on) - 1) printf("[%d]--= %lld\n", l + (i - (m + 1)), A[l + (i - (m + 1))]);
		A[i] = mod(A[i] - A[l + (i - (m + 1))] + modn);
	}
	return last(A, m + 1, r);
}

ll A[1 << 23], B[1 << 23];

inline ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}

ll C[1 << 23];


int solve(int n) {
	on = n;
	if(n == 0) return 0;
	int i, j;
	for(i = 0; i < (1 << n); i++) {
		for(j = 0; j < n; j++)
			if(((i >> j) & 1) && (i & adj[j]))
				break;
		if(j == n) A[i] = 1;
	}
	if(A[(1 << n) - 1] == 1) return 1;
	//for(i = 0; i < (1 << n); i++) B[i] = A[i];
	tf(A, 0, (1 << n) - 1);
	for(i = 0; i < (1 << n); i++) B[i] = C[i] = A[i];
	for(int c = 2; ; c++) {
		for(i = 0; i < (1 << n); i++)
			B[i] = C[i] = mod(A[i] * C[i]);
		if(last(B, 0, (1 << n) - 1)) return c;
	}
}

int S[112], sz[112];
int find(int i) { return S[i] == S[S[i]]? S[i] : S[i] = find(S[i]); }
void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	S[b] = a;
}

char a[100][100]; int adj_[100][100];

int main() {
	int n;
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) S[i] = i, sz[i] = 1;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			scanf(" %c", &a[i][j]);
			if(a[i][j] == 'A') join(i, j);
		}
	vector<int> V;
	for(i = 0; i < n; i++)
		if(find(i) == i && sz[find(i)] > 1)
			V.pb(i);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(find(i) == find(j) && a[i][j] == 'X') {
				puts("-1");
				return 0;
			}
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(a[i][j] == 'X')
				adj_[find(i)][find(j)] = adj_[find(j)][find(i)] = 1;
	//printf("b.size() = %d\n", int(V.size()));
	for(i = 0; i < int(V.size()); i++)
		for(j = 0; j < int(V.size()); j++) {
			adj[i] |= (adj_[V[i]][V[j]] << j);
		}
	printf("%d\n", n - 1 + solve(V.size()));
}