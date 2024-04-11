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

int n, k;
bool can[200][200];
int cnt[200][200];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	FOR(i, n) FOR(j, n){
		char c;
		std::cin >> c;
		if(c == '.') can[i][j] = true;
	}
	FOR(i, n) FOR(j, n){
		bool good = true;
		FOR(l, k) if(!can[i][j+l]) good = false;
		if(good) FOR(l, k) cnt[i][j+l]++;
		good = true;
		FOR(l, k) if(!can[i+l][j]) good = false;
		if(good) FOR(l, k) cnt[i+l][j]++;
	}
	PII max = {0, 0};
	FOR(i, n) FOR(j, n){
		if(cnt[i][j] > cnt[max.X][max.Y]) max = {i, j};
	}
	std::cout << max.X+1 << " " << max.Y+1 << std::endl;

	return 0;
}