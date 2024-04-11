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


bool is_cons(char a){
	if(a == 'a' || a == 'i' || a == 'o' || a == 'u' || a == 'e') return false;
	return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string a, b;
	std::cin >> a >> b;
	if(SZ(a) != SZ(b)) std::cout << "No\n";
	else{
		FOR(i, SZ(a)){
			if(a[i] != b[i]){
				if(is_cons(a[i]) != is_cons(b[i])){
					std::cout << "No\n";
					return 0;
				}
			}
		}
		std::cout << "Yes\n";
	}
	return 0;
}