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

PII operator -(PII a, PII b){
	return MP(a.X-b.X, a.Y-b.Y);
}

PII odw(PII a){
	return MP(-a.X, -a.Y);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<PII> A(n);
	FOR(i, n) std::cin >> A[i].X >> A[i].Y;
	if(n%2 == 1) std::cout << "NO\n";
	else{
	bool good =true;
		FOR(i, n/2){
			if(A[i]-A[i+1] != odw(A[n/2+i]-A[(n/2+i+1)%n])) good =false;
		}
		if(good) std::cout << "YES\n";
		else std::cout << "NO\n";
	}

	return 0;
}