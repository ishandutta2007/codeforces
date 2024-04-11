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

ll la, ra, ta, lb, rb, tb;
ll oa, ob;
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> la >> ra >> ta;
	std::cin >> lb >> rb >> tb;
	if(ta < tb){
		std::swap(la, lb);
		std::swap(ra, rb);
		std::swap(ta, tb);
	}
	ll move = la;
	la -= move;
	ra -= move;
	lb -= move;
	rb -= move;
	move = -lb/tb;
	lb += move*tb;
	rb += move*tb;
	if(lb < 0) lb += tb, rb += tb;
	// std::cout << "," <<  la << "," <<  ra << "," <<  ta << "\n";
	// std::cout << "," <<  lb << "," <<  rb << "," <<  tb << "\n";
	// ll dist = ta - lb;
	ll gcd = std::__gcd(ta, tb);
	ll xd = lb % gcd;
	// std::cout << "XD" << xd << "\n";
	ll x = xd;
	ll y = rb - (lb - xd);
	ll ans = std::min(ra, y) - std::max(la, x) + 1;
	x -= gcd;
	y -= gcd;
	ans = std::max(ans, std::min(ra, y) - std::max(la, x) + 1);
	std::cout << std::max(ans, 0ll) << "\n";
	return 0;
}