#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template <typename T1, typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1, typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
const int MAXN = 2097152;
int n; char buf[MAXN + 5]; ll a[MAXN + 5], b[MAXN + 5];
void FWTor(ll *a, int len, int type) {
	for (int i = 0; i < n; i++) for (int j = 0; j < (1 << n); j++)
		if (j >> i & 1) a[j] += type * a[j ^ (1 << i)];
}
int main() {
	scanf("%d%s", &n, buf);
	for (int i = 0; i < (1 << n); i++) a[i] = (ll)(buf[i] - '0') << (__builtin_popcount(i) * 2);
	scanf("%s", buf);
	for (int i = 0; i < (1 << n); i++) b[i] = (ll)(buf[i] - '0') << (__builtin_popcount(i) * 2);
	FWTor(a, 1 << n, 1); FWTor(b, 1 << n, 1);
	for (int i = 0; i < (1 << n); i++) a[i] *= b[i];
	FWTor(a, 1 << n, -1);
	for (int i = 0; i < (1 << n); i++) putchar(48 + ((a[i] >> (__builtin_popcount(i) << 1)) & 3));
	return 0;
}