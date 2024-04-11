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

int n, B[1000000];
ll A[1000000];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	int max = 0;
	std::cin >> B[0];
	REP(i, 1, n){
		std::cin >> B[i];
		if(B[i] > B[max]) max = i;
	}
	int pos = -1;
	FOR(i, n){
		if(B[i] == B[max] && B[(n+i-1)%n] < B[max]){
			pos = i;
			break;
		}
	}
	if(pos == -1){
		bool good = true;
		FOR(i, n) if(B[i] != 0) good = false;
		if(good){
			std::cout << "YES\n";
			FOR(i, n) std::cout << "1 ";
		}else std::cout << "NO\n";
		return 0;
	}
	std::cout << "YES\n";
	ll sum = 2*B[pos];
	A[pos] = B[pos];
	REP(i, 1, n){
		sum += B[(n+pos-i)%n];
		A[(n+pos-i)%n] = sum;
	}
	FOR(i, n) std::cout << A[i] << " ";
	return 0;
}