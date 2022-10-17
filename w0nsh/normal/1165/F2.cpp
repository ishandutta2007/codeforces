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
std::vector<VI> sale;
int n, m;

bool check(int days){
	VI onday(days+1, 0);
	FOR(i, n){
		auto it = std::upper_bound(sale[i].begin(), sale[i].end(), days-1);
		if(it != sale[i].begin()) onday[*(--it)] += A[i];
		else onday[days] += 2*A[i];
	}
	int have = 0;
	FOR(i, days){
		have++;
		int ile = std::min(onday[i], have);
		onday[i] -= ile;
		have -= ile;
		onday[days] += 2*onday[i];
	}
	if(onday[days] > have) return false;
	return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	A.resize(n);
	sale.resize(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		sale[b].push_back(a);
	}
	FOR(i, n) std::sort(sale[i].begin(), sale[i].end());
	int left = 1;
	int right = 2*200005;
	// int right = 20;
	while(left < right){
		int mid = (left+right)/2;
		if(!check(mid)) left = mid+1;
		else right = mid;
	}
	std::cout << left;
	return 0;
}