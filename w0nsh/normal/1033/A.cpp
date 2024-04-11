#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int n;
PII q, k, t;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	std::cin >> q.X >> q.Y >> k.X >> k.Y >> t.X >> t.Y;
	k.X -= q.X;
	k.Y -= q.Y;
	t.X -= q.X;
	t.Y -= q.Y;
	if(k.X/std::abs(k.X) != t.X/std::abs(t.X) || k.Y/std::abs(k.Y) != t.Y/std::abs(t.Y)){
		std::cout << "NO\n";
		return 0;
	}
	std::cout << "YES\n";
	if(k.X < 0) k.X *= -1, t.X *= -1;
	if(k.Y < 0) k.Y *= -1, t.Y *= -1;
	// if((k.X-k.Y < 0) == (t.X-t.Y < 0)) std::cout << "YES\n";
	// else std::cout << "NO\n";
	return 0;
}