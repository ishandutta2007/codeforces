#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define lson l, m, n * 2
#define rson m + 1, r, n * 2 + 1
#define root 1, n, 1

const long long N = 600010, mod = 1e9 + 9;

long long f[N][2], fs[N][2];
long long n, m;
long long laz[2 * N][2], val[2 * N];

void init () {
	f[1][0] = f[2][1] = 1;
	for (long long i = 3; i < 300010; ++i) {
		for (long long j = 0; j < 2; ++j) {
			(f[i][j] = f[i - 1][j] + f[i - 2][j]) %= mod;
		}
	}
	for (long long i = 1; i < 300010; ++i) {
		for (long long j = 0; j < 2; ++j) {
			(fs[i][j] = fs[i - 1][j] + f[i][j]) %= mod;
		}
	}

}

void build (long long l, long long r, long long n){
    laz[n][0] = laz[n][1] = 0;
    if (l == r){
        scanf ("%d", &val[n]);
        return;
    }
    long long m = l + r >> 1;
    build (lson);
    build (rson);
    val[n] = (val[n * 2] + val[n * 2 + 1]) % mod;
}

void down (long long len, long long n){
    if (laz[n][0] || laz[n][1]){
        long long ls = n << 1, rs = n << 1 | 1;
		long long rl = len >> 1, ll = len - rl;
		long long t[2];
        for (long long i = 0; i < 2; i++)
        {
            (laz[ls][i] += laz[n][i]) %= mod;
            (laz[rs][i] += (t[i] = ((long long)laz[n][0] * f[ll + i + 1][0] % mod + (long long)laz[n][1] * f[ll + i + 1][1] % mod) % mod)) %= mod;
        }
        (val[ls] += ((long long )laz[n][0] * fs[ll][0] % mod + (long long) laz[n][1] * fs[ll][1] % mod) % mod) %= mod;
        (val[rs] += ((long long )t[0] * fs[rl][0] % mod + (long long) t[1] * fs[rl][1] % mod) % mod) %= mod;
		laz[n][0] = laz[n][1] = 0;
    }
}

void update (long long L, long long R, long long l, long long r, long long n) {
    if (L <= l && r <= R){
        long long t[2];
        for (long long i = 0; i < 2; i++)
            (laz[n][i] += (t[i] = f[l - L + i + 1][0] + f[l - L + i + 1][1] % mod)) %= mod;
        (val[n] += (long long)fs[r - l + 1][0] * t[0] + (long long) fs[r - l + 1][1] * t[1] % mod) %= mod;
        return;
    }
    down(r - l + 1, n);
    long long m = (l + r) / 2;
    if (L <= m) update (L, R, lson);
    if (m < R) update (L, R, rson);
    (val[n] = val[n * 2] + val[2 * n + 1]) %= mod;
}

long long query (long long L, long long R, long long l, long long r, long long n){
    if (L <= l && r <= R){
        return val[n];
    }
    long long m = l + r >> 1, res = 0;
    down(r - l + 1, n);
//    cout << L << ' ' << R<< ' ' <<l << ' ' << r << ' ' << m << endl;
    if (L <= m) res += query (L, R, lson);
    if (m < R) res += query (L, R, rson);
    return res % mod;
}

int main () {
    init();
    while (cin >> n >> m) {
		build(root);
		long long op, x, y;
		for (long long i = 0; i < m; ++i) {
			cin >> op >> x >> y;
			if (op == 1) {
				update(x, y, root);
			} else {
				cout << query(x, y, root) << endl;
			}
		}
	}
	return 0;
}