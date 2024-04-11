#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n;
bool ok[1002];
// fazer bottom up
ll memo[2][1002];
//ll solve(int d, int k) {
//	if(k == 0) return ok[d];
//	ll &r = memo[d][k];
//	if(r != -1) return r;
//	r = 0;
//	for(int i = 1; i < n; i++)
//		r += solve((d + i) % n, k - 1);
//	return r = mod(r);
//}
ll& m(int k, int d) {
	return memo[k & 1][d];
}

char s1[2005], s2[2005];
int match[2006][2005];
int main() {
	int i, K, j, k;
	scanf("%s", s1);
	scanf("%s", s2);
	n = strlen(s1);
	for(i = n; i < 2*n; i++)
		s1[i] = s1[i - n], s2[i] = s2[i - n];
	s1[2*n] = s2[2*n] = 0;
	for(i = 2*n - 1; i >= 0; i--)
		for(j = 2*n - 1; j >= 0; j--)
			match[i][j] = (s1[i] == s2[j]) * (1 + match[i + 1][j + 1]);
	for(i = 0; i < n; i++)
		ok[i] = (match[0][i] >= n);
	scanf("%d", &K);
	for(i = 0; i < n; i++)
		m(0, i) = ok[i];
	for(k = 1; k <= K; k++) {
		ll sum = mod(accumulate(memo[!(k&1)], memo[!(k&1)] + n, 0ll));
		for(i = 0; i < n; i++)
			m(k, i) = mod(sum - m(k - 1, i) + modn);
	}
	printf("%d\n", m(K, 0));
}