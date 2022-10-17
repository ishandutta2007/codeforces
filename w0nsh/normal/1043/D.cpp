#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int n, m, cur[10];
VI A[10], pos[10];
bool was[100005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(k, m){
		A[k].resize(n);
		pos[k].resize(n);
		FOR(i, n) std::cin >> A[k][i];
		FOR(i, n) A[k][i]--, pos[k][A[k][i]] = i;
	}
	ll ans = 0;
	TRAV(ch, A[0]){
		if(was[ch]) continue;
		int len = 1;
		FOR(i, m) cur[i] = pos[i][ch];
		while(true){
			bool good = true;
			if(cur[0]+1 >= n) break;
			int next = A[0][cur[0]+1];
			FOR(i, m){
				if(cur[i]+1 >= n || A[i][cur[i]+1] != next){
					good = false;
					break;
				}
			}
			if(!good) break;
			len++;
			was[next] = true;
			FOR(i, m) cur[i]++;
		}
		//std::cout << "len " << len << " on ch " << ch << "\n";
		ans += (1ll*len*(len+1))/2;
	}
	std::cout << ans << "\n";
	return 0;
}