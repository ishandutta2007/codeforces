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
const int N = 1123456;

int bit[2][N], a[N], l[N], r[N], p[N], ans[N];

void add(int bit[], int i, int v) {
	for(i += 2; i < N; i += (i & -i))
		bit[i] ^= v;
}

int query(int bit[], int i) {
	int sum = 0;
	for(i += 2; i; i -= (i & -i))
		sum ^= bit[i];
	return sum;
}
inline int query(int bit[], int l, int r) { return query(bit, r) ^ query(bit, l - 1); }


int main() {
	int i, j, n, q;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &q);
	for(i = 0; i < q; i++)
		scanf("%d %d", &l[i], &r[i]), l[i]--, r[i]--, p[i] = i;
	sort(p, p + q, [](int i, int j) { return l[i] < l[j]; });
	map<int, int> nx;
	for(i = 0; i < n; i++) add(bit[0], i, a[i]), add(bit[1], i, a[i]);
	int r = n;
	for(j = q - 1; j >= 0; j--) {
		i = p[j];
		while(r > l[i]) {
			r--;
			if(nx.count(a[r])) add(bit[1], nx[a[r]], a[r]);
			nx[a[r]] = r;
		}
		ans[i] = query(bit[0], l[i], ::r[i]) ^ query(bit[1], l[i], ::r[i]);
	}
	for(i = 0; i < q; i++)
		printf("%d\n", ans[i]);
}