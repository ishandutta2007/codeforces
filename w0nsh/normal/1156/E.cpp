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
ll ans = 0;

void solve(int a, int b){
	if(a >= b) return;
	int mid = (a+b)/2;
	std::map<int, int> left, right;
	int mx = 0;
	for(int i = mid; i >= a; --i){
		mx = std::max(mx, A[i]);
		left[A[i]] = mx;
	}
	mx = 0;
	for(int i = mid+1; i <= b; ++i){
		mx = std::max(mx, A[i]);
		right[A[i]] = mx;
	}
	TRAV(pr, left){
		int need = pr.Y-pr.X;
		if(right.count(need) == 0) continue;
		if(right[need] < pr.Y) ans++;
	}
	TRAV(pr, right){
		int need = pr.Y-pr.X;
		if(left.count(need) == 0) continue;
		if(left[need] < pr.Y) ans++;
	}
	solve(a, mid);
	solve(mid+1, b);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	solve(0, n-1);
	std::cout << ans;
	return 0;
}