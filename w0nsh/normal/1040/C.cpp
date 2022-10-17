#include <algorithm>
#include <bitset>
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

int n, X[200005];
ll t, A[200005], B[200005];

void fail(int a=-1){
	std::cout << "No\n";
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> t;
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) std::cin >> X[i];
	FOR(i, n) X[i]--;
	FOR(i, n) if(X[i] < i) fail();
	FOR(i, n-1) if(X[i] > X[i+1]) fail();
	FOR(i, n) if(X[i] != i){
		if(X[X[i]] != X[i]) fail(1);
		if(X[i]+1 < n && A[X[i]+1] - 1 == A[X[i]]) fail(2);
	}
	std::vector<bool> back(n);
	int highest = 0;
	FOR(i, n){
		if(X[i] > i) REP(j, std::max(highest, i+1), X[i]+1) back[j] = true;
		if(X[i] > i) highest = std::max(highest, X[i]);
	}
	FOR(i, n){
		if(i < n-1 && back[i+1]) B[i] = A[i+1]+t;
		else B[i] = A[i]+t;
		if(i > 0 && B[i] == B[i-1]) B[i]++;
	}
	std::cout << "Yes\n";
	FOR(i, n) std::cout << B[i] << " ";
	std::cout << "\n";
	return 0;
}