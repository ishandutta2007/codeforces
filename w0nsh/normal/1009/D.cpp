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
#define FOR(i, n) for(int i = 0; i < (n) ++i)
#define REP(i, a, b) for(int i = a; i < (b); ++i)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

void fail(){
	std::cout << "Impossible" << std::endl;
	std::exit(0);
}

int n, m;

std::set<int> primes;
std::vector<PII> edges;

void calc_primes(){
	std::vector<bool> visited(n+1);
	for(int i = 2; i <= n; ++i){
		if(!visited[i]){
			primes.insert(i);
			for(int j = i; j <= n; j += i){
				visited[j] = true;
			}
		}
	}
}

void answer(){
	std::cin >> n >> m;
	long long ln = n;
	long long lm = m;
	if(lm > (ln*(ln-1ll))/2ll) fail();
	if(m < n-1) fail();
	calc_primes();
	for(int i = 2; i <= n; ++i){
		edges.push_back({1, i});
		m--;
		if(m == 0) break;
	}
	bool end = false;
	if(m > 0){
		for(auto it = primes.begin(); it != primes.end(); ++it){
			for(auto jt = std::next(it,1); jt != primes.end(); ++jt){
				edges.push_back({*it, *jt});
				m--;
				if(m == 0){
					end = true;
					break;
				}
			}
			if(end) break;
		}
	}	
	if(m > 0){
		for(int i = 2; i <= n; ++i){
			for(int j = i+1; j <= n; ++j){
				if(primes.find(i) != primes.end() && primes.find(j) != primes.end()) continue;
				if(std::__gcd(i, j) == 1){
					edges.push_back({i, j});
					m--;
					if(m == 0){
						end = true;
						break;
					}
				}
			}
			if(end) break;
		}
	}
	if(m > 0) fail();
	std::cout << "Possible\n";
	for(auto e : edges){
		std::cout << e.X << " " << e.Y << "\n";
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	answer();
	return 0;
}