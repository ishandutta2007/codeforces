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

bool was[200005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	VI A, B;
	std::cin >> n;
	FOR(i, n){
		int a;
		std::cin >> a;
		A.push_back(a);
	}
	int pos = 0;
	FOR(i, n){
		int b;
		std::cin >> b;
		if(was[b]) std::cout << 0 << " ";
		else{
			int num = 0;
			while(A[pos] != b) was[A[pos]] = true, num++, pos++;
			num++, pos++;
			was[b] = true;
			std::cout << num << " ";
		}
	}
	
	return 0;
}