/*

 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)


*/

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 200050;
ll sum[N], sum2[N]; int a[N], T, n; ll ans;
void dfs(int x, ll sc, ll sp, int prc, int prp, int dc, int dp) {
	if (sc * 2 >= sum[1]) return;
	if ((sp + sum[x]) * 2 <= sum[1]) return;
	if (x == n + 1) return ++ans, void();
	if (x < n - 3) {
		if (dp == 1) {
			++ans;
			if (!prc) {
				int l = x, r = n;
				while (l <= r) {
					int mid = (l + r) >> 1;
					if (sp + sum[x] - sum[mid] > sc + sum[mid])
						r = mid - 1;
					else l = mid + 1;
				}
				return ans += n - l + 1, void();
			}
			if (n - prc >= dc && (sp + sum[x] - a[n]) > sc + a[n]) ++ans;
			return;
		}
		if (dc == 2) {
			int l = 0, r = (n - x + 1) >> 1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (sp + sum2[x] + sum2[x + mid * 2 + 1] > sc + sum2[x + 1] - sum2[x + mid * 2 + 1])
					l = mid + 1;
				else r = mid - 1;
			}
			ans += l;
			
			l = 0, r = (n - x - 2) >> 1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (sp + sum2[x] + sum2[x + mid * 2 + 1] - a[n] > sc + sum2[x + 1] - sum2[x + mid * 2 + 1] + a[n])
					l = mid + 1;
				else r = mid - 1;
			}
			ans += l;
			return;
		}
	}
	if (!prc) dfs(x + 1, sc + a[x], sp, x, prp, dc, dp);
	else if (x - prc >= dc) dfs(x + 1, sc + a[x], sp, x, prp, x - prc, dp);
	if (!prp) dfs(x + 1, sc, sp + a[x], prc, x, dc, dp);
	else if (x - prp <= dp) dfs(x + 1, sc, sp + a[x], prc, x, dc, x - prp); 
}

int main() {
//	freopen ("hs.in","r",stdin);
//	freopen ("hs.out","w",stdout);
	for (read(T); T; T--) {
		read(n);
		for (int i = n + 1;i <= n + 6; ++i) sum[i] = sum2[i] = 0;
		ans = 0, a[n + 1] = a[n + 2] = a[n + 3] = 0;
		for (int i = 1;i <= n; ++i) read(a[i]);
		for (int i = n;i >= 1; --i) sum[i] = sum[i + 1] + a[i];
		for (int i = n;i >= 1; --i) sum2[i] = sum2[i + 2] + a[i];
		dfs(1, 0, 0, 0, 0, 0, 1e9), write(ans % 998244353);
	}
	return 0;
}

/*

1
4
9 2 2 2

1
998244353




*/