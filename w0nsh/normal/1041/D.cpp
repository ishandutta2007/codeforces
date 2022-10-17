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

int n, h;
std::vector<PII> A;
std::vector<PII> vec;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> h;
	A.resize(n);
	FOR(i,n) std::cin >> A[i].X >> A[i].Y;
	int best = 0;
	int curans = 0;
	int hei = h;
	int left = 0;
	int right = 0;
	while(left < n && right < n){
		if(left == right){
			curans = A[left].Y-A[left].X;
			hei = h;
			right++;
		}
		while(right < n && A[right].X - A[right-1].Y < hei){
			hei -= A[right].X - A[right-1].Y;
			curans += A[right].Y - A[right-1].Y;
			right++;
		}
		best = std::max(best, curans+hei);
		if(left == n-1) break;
		curans -= A[left].Y-A[left].X + A[left+1].X-A[left].Y;
		hei += A[left+1].X-A[left].Y;
		left++;
	}
	std::cout << best << "\n";
	return 0;
}