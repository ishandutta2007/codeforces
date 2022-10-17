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

void fail(){
	std::cout << ":(";
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::string str;
	std::cin >> n >> str;
	std::string ret;
	if(n % 2 == 1 || str[0] == ')') fail();
	std::stack<int> up;
	str[0] = '(';
	int cnt = 1;
	REP(i, 1, n){
		if(str[i] == ')'){
			if(cnt == 1 && i < n-1){
				if(up.empty()) fail();
				else{
					str[up.top()] = '(';
					up.pop();
					cnt += 2;
				}
			}
			cnt--;
		}else if(str[i] == '(') cnt++;
		else{
			if(cnt == 1 && i < n-1) cnt++, str[i] = '(';
			else cnt--, str[i] = ')', up.push(i);
		}
	}
	if(cnt != 0) fail();
	TRAV(i, str) std::cout << i;
	return 0;
}