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
#include <ctime>
#include <random>
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

int n, m;
bool T[105][105];
bool D[105][105];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(i, n) FOR(j, m){
		char c;
		std::cin >> c;
		if(c == '*') T[i][j] = true;
	}
	std::vector<PR<PII, int> > mov;
	FOR(i, n) FOR(j, m){
		if(!T[i][j]) continue;
		int up = 1;
		while(i - up >= 0 && T[i-up][j]) up++;
		int bot = 1;
		while(i + bot < n && T[i+bot][j]) bot++;
		int left = 1;
		while(j - left >= 0 && T[i][j-left]) left++;
		int right = 1;
		while(j + right < m && T[i][j+right]) right++;
		up--;bot--;right--;left--;
		int r = std::min(std::min(up, bot), std::min(left, right));
		if(r > 0){
			D[i][j] = true;
			mov.push_back({{i, j}, r});
			up = bot = left = right = 0;
			while(++up <= r) D[i-up][j] = true;
			while(++bot <= r) D[i+bot][j] = true;
			while(++left <= r) D[i][j-left] = true;
			while(++right <= r) D[i][j+right] = true;
		}
	}
	FOR(i, n) FOR(j, m) if(T[i][j] && !D[i][j]){
		std::cout << -1 << "\n";
		return 0;
	}
	std::cout << mov.size() << "\n";
	TRAV(pr, mov){
		std::cout << pr.X.X+1 << " " << pr.X.Y+1 << " " << pr.Y << "\n";
	}
	return 0;
}