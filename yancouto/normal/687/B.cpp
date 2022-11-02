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
int dv[N];
int ct[N];

int main() {
	int i, j, n, k, x;
	scanf("%d %d", &n, &k);
	for(ll i = 2; i < N; i++)
		if(!dv[i]) {
			dv[i] = i;
			for(ll j = i * i; j < N; j += i)
				dv[j] = i;
		}
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		while(x != 1) {
			int v = dv[x], c = 0;
			while(!(x % v)) x /= v, c++;
			ct[v] = max(ct[v], c);
		}
	}
	x = k;
	while(x != 1) {
		int v = dv[x], c = 0;
		while(!(x % v)) x /= v, c++;
		if(ct[v] < c) { puts("No"); return 0; }
	}
	puts("Yes");
}