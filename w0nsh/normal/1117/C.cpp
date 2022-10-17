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
typedef std::pair<ll, ll> PLL;
typedef std::vector<int> VI;

int x1, yy1;
int x2, y2;
int sx, sy;
int n;
std::vector<PII> A;

bool check(ll k){
	ll dv = k/n;
	PLL pos = MP(dv*sx+x1, dv*sy+yy1);
	ll nk = k-dv*n;
	FOR(i, nk) pos.X += A[i].X, pos.Y += A[i].Y;
	ll need = std::abs(1ll*x2-pos.X) + std::abs(1ll*y2-pos.Y);
	if(need <= k) return true;
	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> x1 >> yy1 >> x2 >> y2;
	std::cin >> n;
	if(x1 == x2 && yy1 == y2){
		std::cout << 0 << "\n";
		return 0;
	}
	FOR(i, n){
		char ch;
		std::cin >> ch;
		if(ch == 'U') A.push_back(MP(0, 1));
		else if(ch == 'D') A.push_back(MP(0, -1));
		else if(ch == 'R') A.push_back(MP(1, 0));
		else if(ch == 'L') A.push_back(MP(-1, 0));
		sx += A.back().X;
		sy += A.back().Y;
	}
	ll left = 0;
	ll right = 1000000000000000005ll;
	if(!check(right)){
		std::cout << -1 << "\n";
		return 0;
	}
	while(left < right){
		ll mid = (left+right)/2;
		if(check(mid)) right = mid;
		else left = mid+1;
	}
	std::cout << left;
	return 0;
}