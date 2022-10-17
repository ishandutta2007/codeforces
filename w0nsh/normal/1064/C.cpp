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

std::string str;
int n;

bool is_palin(std::string s){
	int left = 0;
	int right = SZ(s)-1;
	while(left < right){
		if(s[left] != s[right]) return false;
		left++;
		right--;
	}
	return true;
}

int count_palin(std::string s){
	int cnt = 0;
	FOR(i, SZ(s)){
		std::string xd = "";
		int j = i;
		while(j < SZ(s)){
			xd += s[j];
			if(is_palin(xd)) cnt++;
			j++;
		}
	}
	return cnt;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	std::cin >> str;
	std::sort(str.begin(), str.end());
	// std::cout << count_palin(str) << "\n";
	std::cout << str << "\n";
	return 0;
}