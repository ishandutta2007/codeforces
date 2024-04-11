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

const int MOD = 998244353;
int n, ans;
std::string str;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> str;
	int left = 0;
	FOR(i, n){
		if(str[i] == str[0]) left++;
		else break;
	}
	int right = 0;
	for(int i = n-1; i >= 0; --i){
		if(str[i] == str[n-1]) right++;
		else break;
	}
	if(str[0] == str[n-1]){
		FOR(i, n){
			ans = (1ll*ans+1ll*(right+1))%MOD;
			if(str[i] != str[0]) break;
		}
	}else{
		FOR(i, n){
			ans++;
			if(str[i] != str[0]) break;
		}
		for(int i = n-1; i >= 0; --i){
			ans++;
			if(str[i] != str[n-1]) break;
		}
		ans--;
	}
	std::cout << ans << "\n";
	return 0;
}