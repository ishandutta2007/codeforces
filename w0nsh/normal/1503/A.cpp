#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

bool check(std::string s){
	int have = 0;
	FOR(i, SZ(s)){
		if(s[i] == '(') have++;
		else have--;
		if(have < 0) return false;
	}
	if(have != 0) return false;
	return true;
}

void solve(){
	int n;
	std::string s;
	std::cin >> n >> s;
	std::string a, b;
	PII cnt = MP(0, 0);
	auto otw = [&](std::string &str){
		str.push_back('(');
	};
	auto zam = [&](std::string &str){
		str.push_back(')');
	};
	int kto = 0;
	int ile = 0;
	int all = 0;
	TRAV(i, s) if(i == '1') all++;
	if(all % 2 != 0){
		std::cout << "NO\n";
		return;
	}
	all /= 2;
	FOR(i, n){
		if(s[i] == '1'){
			if(all){
				all--;
				otw(a);
				otw(b);
			}else{
				zam(a);
				zam(b);
			}
		}else{
			if(kto){
				otw(a);
				zam(b);
			}else{
				otw(b);
				zam(a);
			}
			kto = 1-kto;
		}
	}
	if(check(a) && check(b)){
		std::cout << "YES\n";
		std::cout << a << "\n" << b << "\n";
	}else{
		std::cout << "NO\n";
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}