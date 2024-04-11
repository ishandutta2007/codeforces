#include <bits/stdc++.h>
#define int long long
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

PII operator +(const PII &a, const PII &b){
	return MP(a.X+b.X, a.Y+b.Y);
}
PII operator -(const PII &a, const PII &b){
	return MP(a.X-b.X, a.Y-b.Y);
}

std::vector<PR<PII, int> > days;

int check(PR<PII, int> have){
	int maxdays = (have.X.X/3)*7;
	int rest = have.X.X%3;
	FOR(i, 7){
		if(days[i].X.X == 1 && rest == 0) break;
		if(days[i].X.X == 1) rest--;
		maxdays++;
	}
	int curdays = (have.X.Y/2)*7;
	rest = have.X.Y%2;
	FOR(i, 7){
		if(days[i].X.Y == 1 && rest == 0) break;
		if(days[i].X.Y == 1) rest--;
		curdays++;
	}
	maxdays = std::min(maxdays, curdays);
	curdays = (have.Y/2)*7;
	rest = have.Y%2;
	FOR(i, 7){
		if(days[i].Y == 1 && rest == 0) break;
		if(days[i].Y == 1) rest--;
		curdays++;
	}
	return std::min(curdays, maxdays);
}

signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int a, b, c;
	std::cin >> a >> b >> c;
	PR<PII, int> xd;
	xd = MP(MP(a, b), c);
	days.push_back(MP(MP(1, 0), 0));
	days.push_back(MP(MP(0, 1), 0));
	days.push_back(MP(MP(0, 0), 1));
	days.push_back(MP(MP(1, 0), 0));
	days.push_back(MP(MP(0, 0), 1));
	days.push_back(MP(MP(0, 1), 0));
	days.push_back(MP(MP(1, 0), 0));
	int max = 0;
	FOR(_, 7){
		max = std::max(max, check(xd));
		days.push_back(days[0]);
		days.erase(days.begin());
	}
	std::cout << max;
	return 0;
}