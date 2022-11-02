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

const int N = 212345;

void build(int tr[N << 2], int cp[N], int i, int l, int r) {
	if(l == r) return (void) (tr[i] = cp[l]);
	int m = (l + r) / 2;
	build(tr, cp, 2 * i, l, m);
	build(tr, cp, 2 * i + 1, m + 1, r);
	tr[i] = min(tr[2 * i], tr[2 * i + 1]);
}

int get(int tr[N << 2], int i, int l, int r, int ql, int qr) {
	if(l > qr || r < ql) return 1e9;
	if(l >= ql && r <= qr) return tr[i];
	int m = (l + r) / 2;
	return min(get(tr, 2 * i, l, m, ql, qr), get(tr, 2 * i + 1, m + 1, r, ql, qr));
}

int tr[2][2][N << 2];
int memo[2][2][N];
int l[N], r[N];

int main() {
	int i, n, k;
	scanf("%d %d", &n, &k); k++;
	l[0] = r[0] = 0;
	for(i = 1; i < k; i++)
		scanf("%d %d", &l[i], &r[i]);
	for(int add = 0; add < 2; add++) {
		for(int acc = 0; acc <= 2 * n; acc++)
			memo[k & 1][add][acc] = (acc == n? 0 : 1e9);
		build(tr[k & 1][add], memo[k & 1][add], 1, 0, 2 * n);
	}
	l[k] = 2 * n;
	for(i = k - 1; i >= 0; i--) {
		int i_ = i & 1;
		for(int add = 0; add < 2; add++) {
			for(int acc = 0; acc <= l[i]; acc++) {
				memo[i_][add][acc] = memo[!i_][add][acc + add * (l[i + 1] - l[i])];
				int L = acc + add * (l[i] - l[i]) + (!add) * (l[i + 1] - l[i]);
				int R = acc + add * (r[i] - l[i]) + (!add) * (l[i + 1] - r[i]);
				if(L > R) swap(L, R);
				memo[i_][add][acc] = min(memo[i_][add][acc], get(tr[!i_][!add], 1, 0, 2 * n, L, R) + 1);
				L = acc + (!add) * (l[i] - l[i]) + add * (l[i + 1] - l[i]);
				R = acc + (!add) * (r[i] - l[i]) + add * (l[i + 1] - r[i]);
				if(L > R) swap(L, R);
				memo[i_][add][acc] = min(memo[i_][add][acc], get(tr[!i_][add], 1, 0, 2 * n, L, R) + 2);
				//printf("memo[%d][%d][%d] = %d\n", i, add, acc, memo[i_][add][acc]);
			}
			for(int acc = l[i] + 1; acc <= 2 * n; acc++)
				memo[i_][add][acc] = 1e9;
			build(tr[i_][add], memo[i_][add], 1, 0, 2 * n);
		}
	}
	if(memo[0][0][0] < 1e8) printf("Full\n%d\n", memo[0][0][0]);
	else puts("Hungry");
}