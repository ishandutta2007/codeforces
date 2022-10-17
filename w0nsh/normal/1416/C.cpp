#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

ll tab[35][2];

std::vector<PII> B;
void rec(int a, int b, int p){
	if(a > b || B[a].X == B[b].X) return;
	assert(p >= 0);
	VI fs, sc;
	bool was = false;
	REP(i, a, b+1){
		if((B[i].X & (1<<p)) == 0) assert(!was), fs.push_back(B[i].Y);
		else sc.push_back(B[i].Y), was = true;
	}
	std::sort(fs.begin(), fs.end());
	std::sort(sc.begin(), sc.end());

	TRAV(i, fs) tab[p][0] += std::lower_bound(sc.begin(), sc.end(), i)-sc.begin();
	TRAV(i, sc) tab[p][1] += std::lower_bound(fs.begin(), fs.end(), i)-fs.begin();

	rec(a, a+SZ(fs)-1, p-1);
	rec(a+SZ(fs), b, p-1);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	B.resize(n);
	FOR(i, n){
		B[i] = MP(A[i], i);
	}
	std::sort(B.begin(), B.end());
	rec(0, n-1, 30);

	int ans = 0;
	ll ile = 0;
	FOR(i, 31){
		if(tab[i][0] > tab[i][1]) ans |= (1<<i), ile += tab[i][1];
		else ile += tab[i][0];
	}
	std::cout << ile << " " << ans << "\n";

	return 0;
}