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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	auto read = [&](int &l){
		int x;
		std::cin >> x;
		l = x;
		VI ret(30);
		FOR(i, 30){
			if(x & (1<<i)){
				ret[i] = 1;
			}
		}
		return ret;
	};

	int q;
	std::cin >> q;
	while(q--){
		int fs, sc;
		auto a = read(fs);
		auto b = read(sc);
		if(fs > sc){
			std::cout << "NO\n";
			continue;
		}
		bool good = true;
		int ha = 0, hb = 0;
		FOR(i, 30){
			ha += a[i];
			hb += b[i];
			if(hb > ha){
				good = false;
				break;
			}
		}
		if(good) std::cout << "YES\n";
		else std::cout << "NO\n";
	}

	return 0;
}