#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int MAX = 15000005;
int n, A[300005], sieve[MAX];
bool was[MAX];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n) std::cin >> A[i];
	int gcdall = A[0];
	FOR(i, n) gcdall = std::__gcd(gcdall, A[i]);
	FOR(i, n) sieve[A[i]/gcdall]++;
	int mx = 0;
	for(int i = 2; i < MAX; ++i){
		int cnt = 0;
		if(!was[i]){
			for(int j = i; j < MAX; j += i){
				cnt += sieve[j];
				was[j] = true;
			}
		}
		mx = std::max(cnt, mx);
	}
	std::cout << ((n - mx == 0 || mx == 0) ? -1 : n - mx) << "\n";
	return 0;
}