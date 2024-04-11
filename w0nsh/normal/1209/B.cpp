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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<bool> on(n);
	int ile = 0;
	FOR(i, n){
		char a;
		std::cin >> a;
		if(a=='1') ile++, on[i] = true;
	}
	std::vector<PII> A(n);
	FOR(i, n){
		std::cin >> A[i].X >> A[i].Y;
	}
	int max = ile;
	FOR(sec, 100000){
		FOR(i, n){
			int xd = sec-A[i].Y;
			if(xd >= 0 && xd%A[i].X == 0){
				if(on[i]) ile--;
				else ile++;
				on[i] = !on[i];
			}
		}
		max = std::max(max, ile);
	}
std::cout << max << "\n";
	return 0;
}