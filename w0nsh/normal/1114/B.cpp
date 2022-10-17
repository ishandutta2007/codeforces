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

int n, m, k;
VI A;
std::vector<PII> B;
std::set<int> nt;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	A.resize(n);
	ll sum = 0;
	FOR(i, n){
		std::cin >> A[i];
		B.push_back(MP(A[i], i));
		sum += A[i];
	}
	std::sort(B.begin(), B.end());
	FOR(i, n-m*k) sum -= B[i].X, nt.insert(B[i].Y);
	int hv = 0;
	std::cout << sum << "\n";
	int dn = 0;
	FOR(i, n){
		if(nt.count(i) == 0) hv++;
		if(hv == m && dn < k-1){
			std::cout << i+1 << " ";
			dn++;
			hv = 0;
		}
	}
	return 0;
}