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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >>t;
	while(t--){
		int n, x, y;
		std::cin >> n >> x >> y;

		VI A(n);
		FOR(i, n) std::cin >> A[i];
		FOR(i, n) A[i]--;

		std::vector<VI> pos(n+1);
		FOR(i, n) pos[A[i]].push_back(i);

		int em = -1;
		FOR(i, n+1) if(SZ(pos[i]) == 0) em = i;

		std::priority_queue<PII> que;
		FOR(i, n+1) que.push(MP(SZ(pos[i]), i));

		VI ans(n, -2);

		FOR(_, x){
			int v = que.top().Y;
			que.pop();

			ans[pos[v].back()] = v;
			pos[v].pop_back();
			que.push(MP(SZ(pos[v]), v));
		}

		int need = y-x;
		int left = n-x;

		int most = que.top().X;
		int who = que.top().Y;

		while(most*2 > left){
			que.pop();
			ans[pos[who].back()] = em;
			pos[who].pop_back();
			que.push(MP(SZ(pos[who]), who));

			most = que.top().X;
			who = que.top().Y;
			left--;
		}

		std::vector<PII> hehe;
		FOR(i, n+1) TRAV(j, pos[i]) hehe.push_back(MP(i, j));

    if(SZ(hehe) >= need){
      int jump = SZ(hehe)/2;
      FOR(i, need){
        ans[hehe[i].Y] = hehe[(i+jump)%SZ(hehe)].X;
      }
      REP(i, need, SZ(hehe)) ans[hehe[i].Y] = em;

      need = 0;
    }

		if(need > 0) std::cout << "NO\n";
		else{
			std::cout << "YES\n";
			TRAV(i, ans) std::cout << i+1 << " ";
			std::cout << "\n";
		}

	}

	return 0;
}