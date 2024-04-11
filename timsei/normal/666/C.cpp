#include <bits/stdc++.h>
using namespace std;

const int N = 111111;
const int mod = 1e9 + 7;

int Pow(int x , int y) {
	if(!y) return 1;
	if(y == 1) return x % mod;
	int it = Pow(x * 1ll * x % mod , y >> 1);
	if(y & 1) it = it *1ll * x % mod;
	return it;
}

char s[N];
int fac[N] , inv[N] , n , m , x , y , opt ,  P25[N] , len;

void init(void) {
	fac[0] = P25[0] = inv[0] = 1;
	for(int i = 1;i < N;++ i) fac[i] = fac[i - 1] * 1ll * i % mod , inv[i] = Pow(fac[i] , mod - 2) 
	, P25[i] = P25[i - 1] * 25ll % mod;
}

struct Query {
	int len , n , id;
	friend bool operator < (Query a , Query b) {
		return a.n < b.n;
	}
}Q[N];

int ans[N] , all , dp[N];

vector <Query> A[N];

int C(int x , int y) {
	return fac[x] *1ll * inv[y] % mod * 1ll * inv[x - y] % mod;
}

void solve(int x) {
	sort(A[x].begin() , A[x].end());
	memset(dp , 0 , sizeof(dp));
	dp[x] = 1;
	for(register int i = x + 1;i <= 100000;++ i) {
		dp[i] = dp[i - 1] * 26ll % mod + C(i - 1 , x - 1) * 1ll * P25[i - x] % mod;
		if(dp[i] >= mod) dp[i] -= mod;
	}
	for(auto V : A[x]) ans[V.id] = dp[V.n];
}

main(void) {
	init();
	scanf("%d" , &n);
	scanf("%s" , s + 1); len = strlen(s + 1);
	for(int i = 1;i <= n;++ i) {
		scanf("%d" , &opt);
		if(opt == 1) {
			scanf("%s" , s + 1); len = strlen(s + 1);
		}
		else {
			scanf("%d" , &Q[++ all].n); Q[all].len = len; Q[all].id = all;
			A[Q[all].len].push_back(Q[all]);
		}
	}
	 
	for(register int i = 1;i <= 100000;++ i) if(A[i].size()) {
		solve(i);
	}
	for(register int i = 1;i <= all;++ i) {
		printf("%d\n" , ans[i]);
	}
}