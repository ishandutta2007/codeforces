#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;

int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a % b);
}

int v[212345];

int main() {
	int i, j;
	int m;
	scanf("%d", &m);
	for(i = 0; i < m; i++) {
		scanf("%d", &v[2 * i]);
		if(i) v[2 * i - 1] = v[0];
	}
	m *= 2;
	v[m - 1] = v[0];
	vector<int> vs;
	for(i = 0; i < m; i++) {
		int v = 0;
		for(j = i; j < m; j++) {
			v = gcd(v, ::v[j]);
			vs.pb(v);
		}
	}
	sort(vs.begin(), vs.end());
	vs.erase(unique(vs.begin(), vs.end()), vs.end());
	if(vs.size() != m / 2) { puts("-1"); return 0; }
	for(i = 0; i < m / 2; i++) {
		if(vs[i] != v[2 * i]) {
			puts("-1");
			return 0;
		}
	}
	printf("%d\n", m);
	for(i = 0; i < m; i++)
		printf("%d%c", v[i], " \n"[i == m - 1]);
}