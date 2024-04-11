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
std::vector<PII> ans;
void swap(int a, int b){
	if(std::abs(a-b) >= n/2){
		ans.push_back(MP(a, b));
	}else if(a < n/2 && b < n/2){
		ans.push_back(MP(a, n-1));
		ans.push_back(MP(b, n-1));
		ans.push_back(MP(a, n-1));
	}else if(a >= n/2 && b >= n/2){
		ans.push_back(MP(a, 0));
		ans.push_back(MP(b, 0));
		ans.push_back(MP(a, 0));
	}else{
		if(a > b) std::swap(a, b);
		ans.push_back(MP(a, n-1));
		ans.push_back(MP(0, b));
		ans.push_back(MP(0, n-1));
		ans.push_back(MP(0, b));
		ans.push_back(MP(a, n-1));
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) A[i]--;
	int pos = 0;
	while(pos < n){
		if(A[pos] == pos) pos++;
		else{
			swap(pos, A[pos]);		
			std::swap(A[pos], A[A[pos]]);
		}
	}
	std::cout << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << i.X+1 << " " << i.Y+1 << "\n";
	return 0;
}