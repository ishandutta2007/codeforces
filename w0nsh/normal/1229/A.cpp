#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

bool lep[7007][7007];
int ile[7007];
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<ll> B(n);
	VI A(n);
	FOR(i, n) std::cin >> B[i];
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) FOR(j, n){
		if(((B[i]^B[j])&B[i]) != 0) lep[i][j] = true, ile[i]++;
	}
	std::set<int> wyjeb;
	std::vector<bool> alive(n, true);
	int size = n;
	FOR(i, n){
		if(ile[i] == size-1) wyjeb.insert(i);
	}
	while(SZ(wyjeb)){
		int cur = *wyjeb.begin();
		wyjeb.erase(wyjeb.begin());
		alive[cur] = false;
		size--;
		FOR(j, n) if(alive[j]){
			if(!lep[j][cur]){
				if(ile[j] == size-1) wyjeb.insert(j);
			}else ile[j]--;
		}
	}
	ll ans = 0;
	int xd = 0;
	FOR(i, n) if(alive[i]) ans += A[i], xd++;
	if(xd < 2) std::cout << 0 << "\n";
	else std::cout << ans << "\n";

	
	return 0;
}