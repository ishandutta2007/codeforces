#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int n, k;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<> dis(1, 1000000000);

int los(int a, int b){
	return a + dis(rng)%(b-a+1);
}

bool ask(int a, int b, int c){
	std::cout << "? " << a << " " << b << " " << c << " " << std::flush;
	std::string ans;
	std::cin >> ans;
	if(ans == "Yes") return true;
	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	std::vector<PII> map(n+1);
	std::set<int> dobre;
	FOR(i, n) dobre.insert(i+1);
	int left = n*60;
	VI ers;
	while(left > n+3){
		int first = los(1, n);
		int second = los(1, n);
		while(first == second) second = los(1, n);
		TRAV(i, dobre){
			if(i != second && i != first){
				if(ask(first, i, second)) map[i].X++;
				left--;
				map[i].Y++;
				if(SZ(dobre)-SZ(ers) > 30 && map[i].Y > 20 && (1.0*map[i].X/map[i].Y) < 0.1) ers.push_back(i);
			}
		}
		while(!ers.empty()) dobre.erase(ers.back()), ers.pop_back();
	}
	std::set<PR<double, int> > topka;
	TRAV(i, dobre) topka.insert(MP(1.0*map[i].X/std::max(map[i].Y, 1), i));
	if(k > 2){
		std::cout << "! " << (std::next(topka.end(), -1))->Y << "\n";
		return 0;
	}
	auto it = topka.end();
	VI top;
	int todo = 3;
	while(it != topka.begin() && todo > 0){
		it--;
		todo--;
		top.push_back(it->Y);
	}
	if(SZ(top) == 1) std::cout << "! " << top[0] << "\n";
	else if(ask(top[0], top[1], top[2])) std::cout << "! " << top[1] << "\n";
	else if(ask(top[1], top[0], top[2])) std::cout << "! " << top[0] << "\n";
	else std::cout << "! " << top[2] << "\n";
	return 0;
}