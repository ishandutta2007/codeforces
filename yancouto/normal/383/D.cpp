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

const int N = 1123;
int a[N];
int memo[1123][21234];
int solve(int i, int sum) {
	int &r = memo[i][sum + 10009];
	if(r != -1) return r;
	r = (sum == 0);
	if(i != n) r = mod(ll(r) + solve(i + 1, sum + a[i]) + solve(i + 1, sum - a[i]));
	return r;
}

int main() {
	memset(memo, -1, sizeof memo);
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	ll tot = 0;
	for(i = 0; i < n; i++)
		tot += mod(solve(i, 0) + modn - 1);
	printf("%lld\n", mod(tot));
}