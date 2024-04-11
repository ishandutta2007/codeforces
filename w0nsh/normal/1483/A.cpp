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

void solve(){
	int n, m;
	std::cin >> n >> m;
	std::vector<VI> kto(m);
	std::vector<VI> g(n);
	VI deg(n);
	std::vector<bool> dead(m);
	FOR(i, m){
		int k;
		std::cin >> k;
		FOR(j, k){
			int a;
			std::cin >> a;
			a--;
			kto[i].push_back(a);
			g[a].push_back(i);
			deg[a]++;
		}
	}

	int moge = (m + 1) / 2;

	VI ans(m, -1);
	std::vector<bool> used(n);
	std::queue<int> que;
	FOR(i, n) if(deg[i] <= moge) que.push(i);
	while(SZ(que)){
		int v = que.front();
		que.pop();
		used[v] = true;
		TRAV(ch, g[v]) if(!dead[ch]){
			dead[ch] = true;
			TRAV(x, kto[ch]){
				deg[x]--;
				if(deg[x] == moge) que.push(x);
			}
			ans[ch] = v;
		}
	}

	VI left;
	FOR(i, n) if(!used[i]) left.push_back(i);
	VI cnt(n);
	bool bad = false;
	FOR(i, m){
		if(!dead[i] && SZ(kto[i]) == 1){
			assert(!used[kto[i][0]]);
			cnt[kto[i][0]]++;
			if(cnt[kto[i][0]] > moge){
				bad = true;
				break;
			}
			dead[i] = true;
			ans[i] = kto[i][0];
		}
	}

	if(bad){
		std::cout << "NO\n";
		return;
	}

	FOR(i, m){
		if(!dead[i]){
			bool was = false;
			TRAV(x, kto[i]){
				if(!used[x] && cnt[x] < moge){
					cnt[x]++;
					ans[i] = x;
					dead[i] = true;
					was = true;
					break;
				}
			}
			assert(was);
		}
	}

	std::cout << "YES\n";
	TRAV(i, ans) std::cout << i+1 << " ";
	std::cout << "\n";

	
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}