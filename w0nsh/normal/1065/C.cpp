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

int n, k;
std::vector<int> H, A;
ll ans = 0;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	H.resize(2*100000+1);
	auto it = A.begin();
	int now = n;
	FOR(i, 2*100000+1){
		while(it != A.end() && *it <= i) it++, now--;
		H[i] = now;
	}
	int height = *std::next(A.end(), -1);
	ll cur = 0;
	while(height >= *A.begin()){
		if(cur + H[height] > k){
			ans++;
			cur = 0;
		}
		cur += H[height];
		height--;
	}
	if(cur > 0) ans++;
	std::cout << ans << "\n";
	return 0;
}