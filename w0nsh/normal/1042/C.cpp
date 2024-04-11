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
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	int neg = 0;
	FOR(i, n) if(A[i] < 0) neg++;
	std::vector<bool> zeros(n);
	FOR(i, n) if(A[i] == 0) zeros[i] = true;
	if(neg % 2 == 1){
		int min = -1;
		FOR(i, n) if(A[i] < 0 && (min == -1 || A[i] > A[min])) min = i;
		zeros[min] = true;
	}
	VI del, nt;
	FOR(i, n){
		if(zeros[i]) del.push_back(i);
		else nt.push_back(i);
	}
	if(nt.empty()){
		FOR(i, n-1) std::cout << "1 " << i+1 << " " << i+2 << "\n";
		return 0;
	}
	FOR(i, SZ(del)-1){
		std::cout << "1 " << del[i]+1 << " " << del[i+1]+1 << "\n";
	}
	if(SZ(del) > 0) std::cout << "2 " << del.back()+1 << "\n";
	FOR(i, SZ(nt)-1){
		std::cout << "1 " << nt[i]+1 << " " << nt[i+1]+1 << "\n";
	}
	return 0;
}