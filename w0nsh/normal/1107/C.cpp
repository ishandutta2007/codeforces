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

int n, k;
std::string str;
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	std::cin >> str;
	std::reverse(str.begin(), str.end());
	std::multiset<int> av;
	int pos = 0;
	ll ans = 0;
	while(!str.empty()){
		char nw = str.back();
		while(str.size() && str.back() == nw){
			av.insert(A[pos++]);
			str.pop_back();
		}
		auto it = av.end();
		int cnt = 0;
		do{
			it--;
			ans += *it;
			cnt++;
			if(cnt == k) break; 
		}while(it != av.begin());
		av.clear();
	}
	std::cout << ans;
	return 0;
}