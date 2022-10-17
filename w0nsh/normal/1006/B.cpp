#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = a; i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n, k;
std::vector<int> A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >>  k;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	std::vector<PII> prob(n);
	FOR(i, n) prob[i] = {A[i], i};
	std::sort(prob.begin(), prob.end(), std::greater<PII>());
	std::vector<bool> mark(n);
	ll ans = 0ll;
	FOR(i, k) mark[prob[i].Y] = true, ans += prob[i].X;
	std::cout << ans << "\n";
	int pos = 0;
	int acc = 0;
	while(!mark[pos])
		acc++, pos++;
	pos++;
	acc++;
	REP(i, pos, n){
		if(mark[i]) std::cout << acc << " ", acc = 1;
		else acc++;
	}
	std::cout << acc << "\n";
	return 0;
}