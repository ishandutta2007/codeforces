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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	VI A(4);
	FOR(i, 4) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	int sum = A.back();
	A.pop_back();
	int a = sum - A[0];
	int b = A[1]-a;
	int c = A[2]-a;
	std::cout << a << " " << b << " " << c;
	return 0;
}