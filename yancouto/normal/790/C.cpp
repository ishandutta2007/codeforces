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
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
char s[112];
int v[112];

vector<int> oc[3];
int c[3];

int cost(int i, int A, int v, int k, int x) {
	int l[3] = {v, k, x};
	int nx = oc[A][l[A]];
	int pr = 0;
	for(int g = 0; g < 3; g++)
		pr += max<ll>(0, (lower_bound(oc[g].begin(), oc[g].end(), nx) - oc[g].begin()) - l[g]);
	return pr;
}

const int N = 90;
int memo[N][N][N][2];
int solve(int i, int v, int k, int prevv) {
	if(i == n) return 0;
	int x = i - v - k;
	int &r = memo[i][v][k][prevv];
	if(r != -1) return r;
	r = 1e7;
	if(v < c[0])
		r = min(r, cost(i, 0, v, k, x) + solve(i + 1, v + 1, k, true));
	if(k < c[1] && !prevv)
		r = min(r, cost(i, 1, v, k, x) + solve(i + 1, v, k + 1, false));
	if(x < c[2])
		r = min(r, cost(i, 2, v, k, x) + solve(i + 1, v, k, false));
	return r;
}

int main() {
	memset(memo, -1, sizeof memo);
	int i;
	scanf("%d %s", &n, s);
	for(i = 0; i < n; i++)
		if(s[i] == 'V') v[i] = 0;
		else if(s[i] == 'K') v[i] = 1;
		else v[i] = 2;
	for(i = 0; i < n; i++)
		oc[v[i]].pb(i), c[v[i]]++;
	printf("%d\n", solve(0, 0, 0, 0));
}