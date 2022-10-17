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
	int m, n, k, t;
	std::cin >> m >> n >> k >> t;
	VI A(m);
	FOR(i, m) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	std::reverse(A.begin(), A.end());
	std::vector<std::vector<PII> > trap(n+1);
	FOR(i, k){
		int l, r, d;
		std::cin >> l >> r >> d;
		l--;
		r--;
		trap[l].push_back(MP(d, r));
	}
	int left = 1;
	int right = m+1;
	while(left < right){
		int mid = (left+right)/2;
		int worst = A[mid-1];
		int ans = n+1;
		int pos = -1;
		int lft = -1;
		int upto = -1;
		while(pos < n){
			lft = pos;
			upto = -1;
			pos++;
			TRAV(pr, trap[pos]){
				if(pr.X > worst) upto = std::max(upto, pr.Y);
			}
			if(upto != -1){
				while(pos < upto){
					pos++;
					TRAV(pr, trap[pos]){
						if(pr.X > worst) upto = std::max(upto, pr.Y);
					}
				}
				ans += (pos-lft)*2;
			}
		}
		if(ans > t) right = mid;
		else left = mid+1;
	}
	std::cout << left-1 << "\n";
	return 0;
}