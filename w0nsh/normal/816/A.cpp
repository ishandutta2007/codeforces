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

std::string ts(int h, int m){
	std::string a = std::to_string(h);
	if(SZ(a) == 1) a = "0"+a;
	std::string b = std::to_string(m);
	if(SZ(b) == 1) b = "0"+b;
	return a + ":" + b;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string str;
	std::cin >> str;
	int h = std::stoi(str.substr(0, 2));
	int m = std::stoi(str.substr(3));
	int cnt = 0;
	while(true){
		std::string a = ts(h, m);
		std::string b = a;
		std::reverse(b.begin(), b.end());
		if(a == b) break;
		m++;
		if(m == 60){
			m = 0;
			h++;
			if(h == 24) h = 0;
		}
		cnt++;
	}
	std::cout << cnt;
	return 0;
}