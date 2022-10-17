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

long long n, m;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	long long sum = 0;
	while(m--){
		long long a, b;
		std::cin >> a >> b;
		if(b < 0){
			sum += a*n;
			if(n%2ll == 1ll){
				sum += b*((n/2ll)*(1ll+(n/2ll)));
			}else{
				sum += b*((n/2ll)*(1ll+(n/2ll)))/2ll;
				sum += b*((n/2ll-1)*(n/2ll))/2ll;
			}
		}else{
			sum += a*n;
			sum += b*(n*(n-1ll)/2ll);
		}
	}
	std::cout << std::fixed << std::setprecision(12) << (double)sum / (double)n << "\n";
	return 0;
}