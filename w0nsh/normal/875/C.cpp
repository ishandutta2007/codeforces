#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

void fail(){
	std::cout << "No\n";
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<VI> A(n);
	FOR(i, n){
		int l;
		std::cin >> l;
		A[i].resize(l);
		FOR(j, l) std::cin >> A[i][j], A[i][j]--;
	}

	std::vector<VI> g(m);
	std::vector<bool> mogo(m), niemogo(m);

	FOR(i, n-1){
		FOR(j, SZ(A[i])){
			int my = A[i][j];
			int his = -1;
			if(SZ(A[i+1]) > j) his = A[i+1][j];
			if(my == his) continue;
			if(my > his){
				if(his == -1) fail();
				niemogo[his] = true;
				mogo[my] = true;
			}else{
				g[his].push_back(my);
			}
			break;
		}
	}

	std::vector<bool> vis(m);
	
	VI ans;

	std::function<void(int)> dfs = [&](int v){
		vis[v] = true;
		ans.push_back(v);
		if(niemogo[v]) fail();
		TRAV(ch, g[v]) if(!vis[ch]) dfs(ch);
	};

	FOR(i, m) if(!vis[i] && mogo[i]) dfs(i);

	std::cout << "Yes\n";
	std::cout << SZ(ans) << "\n";
	std::sort(ans.begin(), ans.end());
	TRAV(i, ans) std::cout << i+1 << " ";

	return 0;
}