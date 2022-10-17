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

int n;
VI A;
bool was[300005];

int los(int a, int b){
	return a + std::rand()%(b-a+1);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::srand(294892);
	std::cin >> n;
	FOR(i, n){
		int a;
		std::cin >> a;
		was[a] = true;
	}
	if(was[1]){
		std::cout << 1 << "\n";
		return 0;
	}
	REP(i, 1, 300005){
		if(was[i]){
			A.push_back(i);
			int j = i;
			while(j < 300005){
				was[j] = false;
				j += i;
			}
		}
	}
	int tr = 4000000;
	int ans = 10;
	while(tr-- && ans > 1){
		int cur = 1;
		int gc = A[los(0, SZ(A)-1)];
		while(cur < ans && gc > 1){
			cur++;
			gc = std::__gcd(gc, A[los(0, SZ(A)-1)]);
		}
		ans = cur;
	}
	std::cout << (ans == 10 ? -1 : ans) << "\n";
	return 0;
}