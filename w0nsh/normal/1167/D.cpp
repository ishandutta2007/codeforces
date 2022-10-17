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

VI ans;
int n;
std::string str;

// bool check(int mx){
// 	int h1 = 0;
// 	int h2 = 0;
// 	FOR(i, n){
// 		if(str[i] == '(')
// 	}
// }

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> str;
	ans.resize(n);
	// int left = 1;
	// int right = 1000000;
	// while(left < right){
	// 	int mid = (left+right)/2;
	// 	if(!check(mid)) left = left+1;
	// 	else right = mid;
	// }
	// check(left);
	int kto[2];
	kto[1] = 0;
	kto[0] = 0;
	std::string ans;
	FOR(i, n){
		if(str[i] == '('){
			ans.push_back('0'+kto[0]);
			kto[0] = (kto[0]+1)%2;
		}else{
			ans.push_back('0'+kto[1]);
			kto[1] = (kto[1]+1)%2;
		}
	}
	std::cout << ans;
	return 0;
}