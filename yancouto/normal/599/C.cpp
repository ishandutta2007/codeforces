#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 100009;
int st[N], sn = 0;
int main() {
	int cur_max, x, n, i;
	scanf("%d", &n);
	scanf("%d", &cur_max);
	for(i = 1; i < n; i++) {
		scanf("%d", &x);
		if(x >= cur_max) {
			st[sn++] = cur_max;
			cur_max = x;
		} else {
			while(sn > 0 && st[sn - 1] > x)
				sn--;
		}
	}
	printf("%d\n", sn + 1);
}