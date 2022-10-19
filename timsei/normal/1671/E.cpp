#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int mod = 998244353;


char s[N * 10];
int n, x, dp[(1 << 18) + 1], mx = (1 << n), Hash[(1 << 18) + 1], cnt = 2;

#define pii pair <int, int>
#define mp make_pair

map <pii, int> Map[2];

int solve(int x) {
	if(x * 2 >= mx) {
		if(s[x] == 'A') Hash[x] = 1;
		else Hash[x] = 2;
		return 1;
	}
	dp[x] = 1LL * solve((x << 1)) * solve((x << 1 | 1)) % mod;
	int a = Hash[(x << 1)], b = Hash[(x << 1 | 1 )];
	if(a > b) swap(a, b);
	if(!Map[s[x] - 'A'][mp(a, b)]) Map[s[x] - 'A'][mp(a, b)] = ++ cnt;
	Hash[x] = Map[s[x] - 'A'][mp(a, b)];
	if(a != b) {
		dp[x] = 2LL * dp[x] % mod;
	}

	return dp[x];
}

void rmain() {
	int n;
	cin >> n; mx = (1 << n); ; cnt = 2;
	scanf("%s", s + 1);
	printf("%d\n", solve(1));
}


int main() {
	int t;
	for(t = 1; t --;) {
		rmain();
	}
}