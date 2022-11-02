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

int a[500009];
int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	i = j = 1;
	int mx = 0;
	while(i < n - 1) {
		while(i < n - 1 && (a[i - 1] == a[i] || a[i] == a[i + 1])) i++;
		if(i == n - 1) break;
		for(j = i + 1; j < n - 1 && a[j - 1] != a[j] && a[j] != a[j + 1]; j++);
		j--;
		int tm = (j - i + 2) / 2;
		mx = max(mx, tm);
		for(int k = i; k <= j; k++) {
			int dist = min(k - i + 1, j - k + 1);
			if(dist & 1) a[k] = !a[k];
		}
		i = j + 1;
	}
	printf("%d\n", mx);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}