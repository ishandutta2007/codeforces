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
	int n, k;
	std::cin >> n >> k;
	VI A(n);
	int t1 = 0, t2 = 0;
	FOR(i, n) std::cin >> A[i];
	FOR(i, n){
		if(A[i] == 1) t1++;
		else t2++;
	}
	int mx = 0;
	FOR(i, n){
		int pos = i;
		int a = 0;
		int b = 0;
		while(pos < n){
			if(A[pos] == 1) a++;
			else b++;
			pos += k;
		}
		pos = i-k;
		while(pos >= 0){
			if(A[pos] == 1) a++;
			else b++;
			pos -= k;
		}
		int xd = std::abs((t1-a)-(t2-b));
		mx = std::max(mx, xd);
	}
	std::cout << mx;
	return 0;
}