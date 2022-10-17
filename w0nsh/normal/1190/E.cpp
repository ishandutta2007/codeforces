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
const ld PI = 3.141592653589793;

int n, m;
std::vector<ld> dist, ang;
std::vector<PLD> range, A;
int nxt[20][200005];

bool check(ld r){
	FOR(i, n){
		ld angle = std::acos(r/dist[i]);
		range[i] = MP(ang[i]-angle, ang[i]+angle);
		if(range[i].X < 0) range[i].X += PI*2;
		// if(range[i].Y > PI*2) range[i].Y -= PI*2;
		if(range[i].Y < range[i].X) range[i].Y += PI*2;
	}
	std::vector<PR<PLD, int> > rng;
	FOR(i, n){
		rng.push_back(MP(MP(range[i].X, range[i].Y + (range[i].Y < range[i].X ? PI*2 : 0)), i));
		rng.push_back(rng.back());
		rng.back().X.X += PI*2;
		rng.back().X.Y += PI*2;
		rng.back().Y = n+i;
	}
	std::sort(rng.begin(), rng.end());
	std::vector<PR<ld, PII> > events;
	// -1 open
	// 1 close
	FOR(i, 2*n){
		events.push_back(MP(rng[i].X.X, MP(-1, i)));
		events.push_back(MP(rng[i].X.Y, MP(1, i)));
	}
	std::sort(events.begin(), events.end());
	std::vector<bool> dead(2*n);
	// TRAV(i, rng) std::cout << i.Y << " ";
	// std::cout << std::endl;
	std::queue<int> open;
	TRAV(ev, events){
		if(ev.Y.X == -1){
			// std::cout << "open ";
			open.push(ev.Y.Y);
		}else{
			// std::cout << "close ";
			int lastopen = open.back();
			while(!open.empty() && open.front() <= ev.Y.Y){
				nxt[0][open.front()] = lastopen+1;
				open.pop();
			}
		}
		// std::cout << ev.Y.Y << std::endl;
	}
	// FOR(i, 2*n){
		// std::cout << i <<": " << nxt[0][i] << std::endl;
	// }
	// int xd;
	// std::cin >> xd;
	REP(l, 1, 20) FOR(i, 2*n) nxt[l][i] = (nxt[l-1][i] == 2*n ? 2*n : nxt[l-1][nxt[l-1][i]]);
	FOR(i, n){
		int left = m;
		int cur = i;
		for(int l = 19; l >= 0; --l){
			if((1<<l) <= left){
				left -= (1<<l);
				cur = nxt[l][cur];
				if(cur-i >= n) return true;
			}
		}
	}
	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	A.resize(n);
	range.resize(n);
	dist.resize(n);
	ang.resize(n);
	FOR(i, n) std::cin >> A[i].X >> A[i].Y;
	FOR(i, n) dist[i] = std::sqrt(A[i].X*A[i].X+A[i].Y*A[i].Y);
	FOR(i, n){
		ang[i] = std::atan2(A[i].Y, A[i].X);
		if(ang[i] < 0) ang[i] += PI*2;
	}
	ld left = 0;
	ld right = *std::min_element(dist.begin(), dist.end());
	while(right - left > 0.0000000001){
		ld mid = (left+right)/2;
		if(check(mid)) left = mid;
		else right = mid;
	}
	std::cout << std::setprecision(20) << std::fixed << (left+right)/2 << std::endl;
	return 0;
}