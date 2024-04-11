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


int n;
std::vector<PII> A;
VI ans;

void fail(){
	std::cout << "NO\n";
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	ans.resize(n, -1);
	FOR(i, n) std::cin >> A[i].X;
	FOR(i, n) std::cin >> A[i].Y;
	int curcnd = n;
	while(true){
		VI zeros;
		FOR(i, n){
			if(A[i].X < 0 || A[i].Y < 0) fail();
			if(ans[i] == -1 && A[i].X == 0 && A[i].Y == 0) zeros.push_back(i), ans[i] = curcnd;
		}
		if(SZ(zeros) == 0) break;
		curcnd--;
		int after = 0;
		for(int i = n-1; i >= 0; --i){
			if(!zeros.empty() && zeros.back() == i) zeros.pop_back(), after++;
			else if(ans[i] == -1){
				A[i].X -= SZ(zeros);
				A[i].Y -= after;
			}
		}
	}
	FOR(i, n) if(ans[i] == -1) fail();
	std::cout << "YES\n";
	TRAV(i, ans) std::cout << i << " ";
	return 0;
}