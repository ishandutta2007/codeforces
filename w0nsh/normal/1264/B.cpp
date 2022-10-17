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

void rec(VI state, VI mam, int pos){
	int sum = 0;
	FOR(i, 4) sum += state[i];
	if(sum == 0){
		std::cout << "YES\n";
		TRAV(i, mam) std::cout << i << " ";
		std::exit(0);
	}
	if(pos > 0 && state[pos-1] > 0){
		int ps = pos;
		int ot = pos-1;
		VI nw = mam;
		VI st = state;
		while(st[ot] > 0){
			st[ot]--;
			nw.push_back(ot);
			std::swap(ps, ot);
		}
		rec(st, nw, ps);
	}
	if(pos < 3 && state[pos+1] > 0){
		int ps = pos;
		int ot = pos+1;
		VI nw = mam;
		VI st = state;
		while(st[ot] > 0){
			st[ot]--;
			nw.push_back(ot);
			std::swap(ps, ot);
		}
		rec(st, nw, ps);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	if(a > 0) rec(VI{a-1, b, c, d}, VI{0}, 0);
	if(b > 0) rec(VI{a, b-1, c, d}, VI{1}, 1);
	if(c > 0) rec(VI{a, b, c-1, d}, VI{2}, 2);
	if(d > 0) rec(VI{a, b, c, d-1}, VI{3}, 3);
	std::cout << "NO\n";
	return 0;
}