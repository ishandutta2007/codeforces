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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<ll> A(n), B(n/2);
	FOR(i, n/2) std::cin >> B[i];
	ll left = 0;
	ll right = B[0];
	FOR(i, n/2){
		ll l = left;
		ll r;
		if(B[i]-l > right) r = right;
		else r = B[i]-l;
		l = B[i]-r;
		A[i] = l;
		A[n-1-i] = r;
		left = l;
		right = r;
	}
	TRAV(i, A) std::cout << i << " ";
	return 0;
}