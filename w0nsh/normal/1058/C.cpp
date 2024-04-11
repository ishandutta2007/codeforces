#include <bits/stdc++.h>
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

int n, A[105];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string str;
	std::cin >> n >> str;
	FOR(i, n) A[i] = str[i]-'0';
	bool allzero = true;
	FOR(i, n) if(A[i] != 0) allzero = false;
	if(allzero){
		std::cout << "YES\n";
		return 0;
	}
	int sum = 0;
	FOR(i, n-1){
		sum += A[i];
		if(sum == 0) continue;
		int cur = 0;
		bool good = true;
		int resets = 0;
		FOR(j, n){
			cur += A[j];
			if(cur > sum){
				good = false;
				break;
			}
			if(cur == sum) cur = 0, resets++;
		}
		if(good && cur == 0 && resets > 1){
			std::cout << "YES\n";
			return 0;
		}
	}
	std::cout << "NO\n";
	return 0;
}