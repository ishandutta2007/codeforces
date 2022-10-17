#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

constexpr int MAXN = 200005;
constexpr int K = 19;
int LG[MAXN+1];
ll st[MAXN][K + 1];


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	LG[1] = 0;
	for (int i = 2; i <= MAXN; i++)
		LG[i] = LG[i/2] + 1;

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::vector<ll> B(n);
		FOR(i, n) std::cin >> B[i];
		std::vector<ll> A(n-1);
		FOR(i, n-1) A[i] = std::abs(B[i+1] - B[i]);
		n--;

		for (int i = 0; i < n; i++)
			st[i][0] = A[i];

		for (int j = 1; j <= K; j++)
			for (int i = 0; i + (1 << j) <= n; i++)
				st[i][j] = std::gcd(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

		auto get = [&](int L, int R){
			if(R >= n) return false;
			int j = LG[R - L + 1];
			return std::gcd(st[L][j], st[R - (1 << j) + 1][j]) > 1;
		};

		int ans = 0;
		FOR(start, n){
			int left = 0;
			int right = n;
			while(left < right){
				int mid = (left+right)/2;
				if(get(start, start+mid)){
					left = mid+1;
				}else{
					right = mid;
				}
			}
			ans = std::max(ans, left);
		}

		std::cout << ans+1 << "\n";

	}

	return 0;
}