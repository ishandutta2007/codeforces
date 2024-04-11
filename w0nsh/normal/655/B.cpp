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

const int LOG = 18;
int t[1<<(LOG+1)];
int add(int a){
	a += (1<<LOG);
	while(a >= 1){
		t[a]++;
		a>>=1;
	}
}
int query(int a, int b){
	a += (1<<LOG);
	b += (1<<LOG)+1;
	int sum = 0;
	while(a<b){
		if(a&1) sum += t[a++];
		if(b&1) sum += t[--b];
		a>>=1;b>>=1;
	}
	return sum;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	VI A;
	FOR(i, n) A.push_back(i);
	FOR(i, std::min(k, n/2)){
		std::swap(A[i], A[n-i-1]);
	}
	ll ans = 0;
	FOR(i, n){
		ans += query(A[i], n-1);
		add(A[i]);
	}
	std::cout << ans;
	return 0;
}