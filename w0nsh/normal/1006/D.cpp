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

int n;
std::string A, B;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	std::cin >> A >> B;
	int ans = 0;
	if(n % 2 == 1 && A[n/2] != B[n/2]) ans++;
	int left = (n-1)/2 - (n%2==1 ? 1 : 0);
	int right = (n+1)/2;
	while(left >= 0){
		if(A[left] != A[right] || B[left] != B[right]){
			if(B[left] == B[right]) ans++;
			else{
				std::map<char, int> map;
				map[A[left]]++; map[A[right]]++;
				if(map[B[left]] > 0) map[B[left]]--;
				else ans++;
				if(map[B[right]] <= 0) ans++;
			}
		}	
		left--;
		right++;
	}
	std::cout << ans << "\n";
	return 0;
}