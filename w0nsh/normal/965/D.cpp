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

const ll INF = 1000000000ll*1000000000ll;

int w, l;
std::vector<ll> have, A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> w >> l;
	A.resize(w);
	have.resize(w);
	A[w-1] = INF;
	FOR(i, w-1) std::cin >> A[i];
	FOR(i, l) have[i] = A[i];
	int left = 0;
	REP(i, l, w){
		while(left + l < i) left++;
		while(left < i && have[left] <= A[i]){
			have[i] += have[left];
			A[i] -= have[left];
			have[left] = 0;
			left++;
		}
		if(left < i){
			have[left] -= A[i];
			have[i] += A[i];
			A[i] = 0;
		}
	}
	std::cout << have[w-1] << "\n";
	return 0;
}