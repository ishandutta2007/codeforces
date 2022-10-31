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
const int N = 612345;
int a[N], z[N], o[N], g;

int main() {
	int i, n, k;
	scanf("%d %d", &n, &k);
	int ce = 0;
	int all0 = 0;
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int j = 0, mx = 0, bestl = 0, bestr = -1;
	for(i = 0; i < n; i++) {
		while(j < n && (a[j] || k > 0)) {
			if(!a[j]) k--;
			j++;
		}
		if(j - i > mx)
			bestl = i, bestr = j - 1;

		mx = max(mx, j - i);
		if(i == j) { j++; continue; }
		if(!a[i]) k++;
	}
	for(i = bestl; i <= bestr; i++)
		a[i] = 1;
	printf("%d\n", mx);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}