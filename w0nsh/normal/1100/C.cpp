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
typedef long double ld;
typedef std::pair<ld, ld> PLD;
#define PI 3.14159265359

int n;
ld r;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> r;
	ld a = std::cos((2.0/n)*PI);
	ld b = r;
	ld xd = std::sqrt(2)*(std::sqrt(b*b-a*b*b))-a*b+b;
	xd /= a+1;
	std::cout << std::fixed << std::setprecision(12) << xd;
	return 0;
}