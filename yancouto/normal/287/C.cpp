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

int p[100009];
int main() {
	int i, n;
	scanf("%d", &n);
	if(n == 1) { puts("1"); return 0; }
	if((n & 2) || n == 2) { puts("-1"); return 0; }
	p[(n + 1) / 2] = (n + 1) / 2;
	for(i = 1; i <= (n / 2); i += 2) {
		p[i] = i + 1;
		p[i + 1] = n - i + 1;
		p[n - i + 1] = n - i;
		p[n - i] = i;
	}
	for(i = 1; i <= n; i++)
		printf("%d ", p[i]);
	putchar('\n');
}