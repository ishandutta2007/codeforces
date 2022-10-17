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
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n, m;
std::vector<int> A, B;

void answer(){
	std::cin >> n >> m;
	A.resize(n);
	B.resize(m);
	FOR(i, n) std::cin >> A[i];
	FOR(i, m) std::cin >> B[i];
	int cur = 0;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(cur == B.size()) break;
		if(B[cur] >= A[i]){
			ans++;
			cur++;
		}
	}
	std::cout << ans << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	answer();
	return 0;
}