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

	int n, m;
	std::cin >> n >> m;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::vector<PII> B(m);
	std::vector<std::vector<PII> > map(n);
	FOR(i, m){
		std::cin >> B[i].X >> B[i].Y;
		B[i].X--;B[i].Y--;
		map[B[i].X].push_back(MP(B[i].Y, i));
		map[B[i].Y].push_back(MP(B[i].X, i));
		A[B[i].X]--; A[B[i].Y]--;
	}

	VI ord;
	std::set<int> done;

	std::queue<int> que;
	FOR(i, n) if(A[i] >= 0) que.push(i);

	while(SZ(que)){
		int i = que.front();
		que.pop();
		TRAV(j, map[i]){
			if(A[j.X] < 0){
				A[j.X]++;
				ord.push_back(j.Y);
				done.insert(j.Y);
				if(A[j.X] == 0) que.push(j.X);
			}
		}
	}

	FOR(i, n) if(A[i] < 0){
		std::cout << "DEAD\n";
		return 0;
	}

std::cout << "ALIVE\n";
	FOR(i, m) if(done.count(i) == 0) std::cout << i+1 << " ";
	std::reverse(ord.begin(), ord.end());
	TRAV(i, ord) std::cout << i+1 << " ";

	return 0;
}