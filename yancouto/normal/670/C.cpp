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
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif

map<int, int> ct;

int b[212345], c[212345];
int main() {
	int i, j, n, x, m;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		ct[x]++;
	}
	scanf("%d", &m);
	for(i = 0; i < m; i++)
		scanf("%d", &b[i]);
	for(i = 0; i < m; i++)
		scanf("%d", &c[i]);
	pii mx(-1, -1); int ind;
	for(i = 0; i < m; i++) {
		pii k(ct[b[i]], ct[c[i]]);
		if(k > mx) {
			mx = k;
			ind = i;
		}
	}
	printf("%d\n", ind + 1);
}