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

int n;
std::string str;
std::vector<std::string> vec;
int XD[2][101];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	int l1 = -1, l2 = -1;
	FOR(i, n*2-2){
		std::string a;
		std::cin >> a;
		vec.push_back(a);
		if(SZ(a) == n-1){
			if(l1 == -1) l1 = i;
			else l2 = i;
		}
	}
	FOR(i, 2) FOR(j, 101) XD[i][j] = -1;
	FOR(i, SZ(vec)){
		if(XD[0][SZ(vec[i])] == -1) XD[0][SZ(vec[i])] = i;
		else XD[1][SZ(vec[i])] = i;
	}
	bool good = true;
	FOR(i, n-2){
		if(vec[l1][i+1] != vec[l2][i]){
			good = false;
		}
	}
	if(good){
		FOR(i, n-1) str.push_back(vec[l1][i]);
		str.push_back(vec[l2].back());
		TRAV(s, vec){
			bool huh = true;
			FOR(j, SZ(s)){
				if(str[j] != s[j]){
					huh = false;
					break;
				}
			}
			if(!huh){
				huh = true;
				FOR(j, SZ(s)){
					if(s[j] != str[SZ(str)-SZ(s)+j]){
						huh = false;
						break;
					}
				}
			}
			if(!huh){
				good = false;
				break;
			}
		}
	}
	if(!good) std::swap(l1, l2);
	str.clear();
	FOR(i, n-1) str.push_back(vec[l1][i]);
	str.push_back(vec[l2].back());
	std::vector<char> ans(n*2-2);
	REP(sz, 1, n){
		good = true;
		std::string a = vec[XD[0][sz]];
		FOR(j, sz){
			if(a[j] != str[j]) good = false;
		}
		if(good){
			a = vec[XD[1][sz]];
			FOR(j, sz){
				if(a[j] != str[n-SZ(a)+j]) good = false;
			}
		}
		if(good){
			ans[XD[0][sz]] = 'P';
			ans[XD[1][sz]] = 'S';
		}else{
			ans[XD[0][sz]] = 'S';
			ans[XD[1][sz]] = 'P';
		}
	}
	TRAV(i, ans) std::cout << i;
	return 0;
}