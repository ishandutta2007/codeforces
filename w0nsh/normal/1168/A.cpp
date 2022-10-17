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

VI A;
int n, m;

bool can(int k){
	int last = 0;
	TRAV(i, A){
		PII p1 = MP(i, std::min(m-1, i+k));
		PII p2 = MP(-1, -1);
		if(i+k >= m) p2 = MP(0, i+k-m);
		if(last > p1.Y && last > p2.Y) return false;
		if(last >= p1.X && last <= p1.Y) continue;
		if(last >= p2.X && last <= p2.Y) continue;
		if(last < p1.X) last = p1.X;
		if(last < p2.X && p2.X != -1 && p2.X < p1.X) last = p2.X;
	}
	return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	A.resize(n);
	FOR(i, n){
		std::cin >> A[i];
	}
	int left = 0;
	int right = m+1;
	while(left < right){
		int mid = (left+right)/2;
		if(!can(mid)) left = mid+1;
		else right = mid;
	}
	std::cout << left << "\n";
	return 0;
}