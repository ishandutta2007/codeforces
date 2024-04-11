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

int n;
ll temp, ans;
int A[300005], par[300005], pref[300005];

int popcnt(ll a){
	int ret = 0;
	while(a > 0) ret += a%2, a>>=1;
	return ret;
}

int zercnt(int a, int b){
	return pref[b+1]-pref[a];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n) std::cin >> temp, A[i] = popcnt(temp);
	// FOR(i, n) std::cout << A[i] << ",";
	par[0] = A[0] % 2;
	REP(i, 1, n) par[i] = (par[i-1]+A[i]%2)%2;
	FOR(i, n) pref[i+1] = pref[i] + (par[i]+1)%2;
	pref[n+1] = pref[n];
	int good = 0;
	FOR(i, n){
		int max = 0, sum = 0;
		int j = i;
		while(j < n){
			sum += A[j];
			max = std::max(max, A[j]);
			if(par[j] == good && 2*max <= sum) ans++;
			// if(par[j] == good && 2*max <= sum) std::cout << "adding " << 1 << " when j = " << j << " i = " << i << "\n";
			j++;
			if(sum > 64 && 2*max <= sum){
				// std::cout << "adding " << (good == 0 ? zercnt(j, n) : n-j+1-zercnt(j, n)) << " from " << j << " to " << n << "\n"; 
				ans += (good == 0 ? zercnt(j, n) : n-j-zercnt(j, n));
				break;
			}
		}
		good = (good+(A[i]%2))%2;
	}
	std::cout << ans << "\n";
	return 0;
}