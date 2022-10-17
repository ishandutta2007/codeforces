#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int get_or(int a, int b){
	std::cout << "or " << a+1 << " " << b+1 << std::endl;
	int ans;
	std::cin >> ans;
	return ans;
}

int get_and(int a, int b){
	std::cout << "and " << a+1 << " " << b+1 << std::endl;
	int ans;
	std::cin >> ans;
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;

	VI xr(n);
	VI nd(n);
	VI rr(n);
	FOR(i, n-1){
		rr[i] = get_or(i, i+1);
		nd[i] = get_and(i, i+1);
		xr[i] = rr[i] ^ nd[i];
	}

	VI A(n);

	int or_heh = get_or(0, 2);

	FOR(b, 30){
		VI tab(n, -1);
		int good = -1;
		FOR(i, n-1){
			if(nd[i] & (1<<b)){
				tab[i] = 1;
				good = i;
				break;
			}
		}
		if(good == -1){
			FOR(i, n-1){
				if(!(rr[i] & (1<<b))){
					tab[i] = 0;
					good = i;
					break;
				}
			}
		}
		if(good == -1){
			if(or_heh & (1<<b)) tab[0] = 1;
			else tab[0] = 0;
			good = 0;
		}

		for(int i = good-1; i >= 0; --i){
			if(xr[i] & (1<<b)){
				tab[i] = 1 - tab[i+1];
			}else{
				tab[i] = tab[i+1];
			}
		}

		for(int i = good+1; i < n; ++i){
			if(xr[i-1] & (1<<b)){
				tab[i] = 1 - tab[i-1];
			}else{
				tab[i] = tab[i-1];
			}
		}

		FOR(i, n) if(tab[i]) A[i] |= (1<<b);
	}

	std::sort(A.begin(), A.end());
	// TRAV(i, A) std::cout << i << " ";
	// std::cout << std::endl;
	std::cout << "finish " << A[k-1] << std::endl;

	return 0;
}