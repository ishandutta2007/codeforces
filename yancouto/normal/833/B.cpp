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

const int N = 41234;

int tr[52][N << 2], lz[52][N << 2];
void unlaze(int k, int i, int l, int r) {
	tr[k][i] += lz[k][i];
	if(l != r)
		lz[k][2 * i] += lz[k][i],
		lz[k][2 * i + 1] += lz[k][i];
	lz[k][i] = 0;
}
void add(int k, int i, int l, int r, int ql, int qr, int x) {
	unlaze(k, i, l, r);
	if(l > qr || r < ql) return;
	if(l >= ql && r <= qr) {
		lz[k][i] = x;
		unlaze(k, i, l, r);
		return;
	}
	int m = (l + r) / 2;
	add(k, 2 * i, l, m, ql, qr, x);
	add(k, 2 * i + 1, m + 1, r, ql, qr, x);
	tr[k][i] = max(tr[k][2 * i ], tr[k][2 * i + 1]);
}

int get(int k, int i, int l, int r, int ql) {
	unlaze(k, i, l, r);
	if(r < ql) return INT_MIN;
	if(l >= ql) return tr[k][i];
	int m = (l + r) / 2;
	return max(get(k, 2 * i, l, m, ql), get(k, 2 * i + 1, m + 1, r, ql));
}


int memo[N][52];
int a[N], nx[N];

int main() {
	int i, K, k;
	rd(n); rd(K);
	for(i = 0; i < n; i++) rd(a[i]);
	for(i = 0; i <= n; i++) nx[i] = n;
	for(i = n - 1; i >= 0; i--) {
		for(k = K; k > 0; k--) {
			//printf("calc(%d, %d)\n", i, k);
			//for(int g = i; g < n; g++)
			//	printf("till %d is %d+%d=%d\n", g, get(g), memo[g+1][k-1], get(g)+memo[g+1][k-1]);
			add(k - 1, 1, 0, n - 1, i, nx[a[i]] - 1, 1);
			memo[i][k] = get(k - 1, 1, 0, n - 1, i);
			add(k, 1, 0, n - 1, i - 1, i - 1, memo[i][k]);
			//printf("memo[%d][%d] = %d\n", i, k, memo[i][k]);
		}
		nx[a[i]] = i;
	}
	printf("%d\n", memo[0][K]);
}