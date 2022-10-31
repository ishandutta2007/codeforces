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

int M[400], F[400];
int main() {
	int i, j, n, l, r; char c;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf(" %c %d %d", &c, &l, &r);
		for(j = l; j <= r; j++)
			(c == 'M'? M : F)[j]++;
	}
	int mx = 0;
	for(i = 1; i <= 366; i++)
		mx = max(mx, 2*min(M[i], F[i]));
	printf("%d\n", mx);
}