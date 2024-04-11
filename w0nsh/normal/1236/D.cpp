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

std::vector<VI> sx, sy;
PII operator +(PII a, PII b){
	return MP(a.X+b.X, a.Y+b.Y);
}

std::vector<PII> dir = {MP(0, 1), MP(1, 0), MP(0, -1), MP(-1, 0)};
int mx[4];
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	int k;
	std::cin >> k;
	sy.resize(n);
	sx.resize(m);
	FOR(i, k){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		sy[a].push_back(b);
		sx[b].push_back(a);
	}
	FOR(i, n) std::sort(sy[i].begin(), sy[i].end());
	FOR(i, m) std::sort(sx[i].begin(), sx[i].end());
	mx[0] = m-1;
	mx[1] = n-1;
	mx[2] = 0;
	mx[3] = 0;
	PII pos = MP(0, -1);
	int kt = 0;
	ll ile = 0;
	while(true){
		if(kt == 0){
			auto it = std::upper_bound(sy[pos.X].begin(), sy[pos.X].end(), pos.Y);
			int gdz = mx[kt];
			if(it != sy[pos.X].end()) gdz = std::min(gdz, *it-1);
			if(gdz <= pos.Y) break;
			ile += gdz-pos.Y;
			mx[3] = pos.X+1;
			pos.Y = gdz;
		}else if(kt == 1){
			auto it = std::upper_bound(sx[pos.Y].begin(), sx[pos.Y].end(), pos.X);
			int gdz = mx[kt];
			if(it != sx[pos.Y].end()) gdz = std::min(gdz, *it-1);
			if(gdz <= pos.X) break;
			ile += gdz-pos.X;
			mx[0] = pos.Y-1;
			pos.X = gdz;
		}else if(kt == 2){
			auto it = std::lower_bound(sy[pos.X].begin(), sy[pos.X].end(), pos.Y);
			int gdz = mx[kt];
			if(it != sy[pos.X].begin()){
				--it;
				gdz = std::max(gdz, *it+1);
			}
			if(gdz >= pos.Y) break;
			ile += pos.Y-gdz;
			mx[1] = pos.X-1;
			pos.Y = gdz;
		}else{
			auto it = std::lower_bound(sx[pos.Y].begin(), sx[pos.Y].end(), pos.X);
			int gdz = mx[kt];
			if(it != sx[pos.Y].begin()){
				--it;
				gdz = std::max(gdz, *it+1);
			}
			if(gdz >= pos.X) break;
			ile += pos.X-gdz;
			mx[2] = pos.Y+1;
			pos.X = gdz;
		}
		kt = (kt+1)%4;
	}
	if(ile  == 1ll*n*m-1ll*k) std::cout << "Yes\n";
	else std::cout << "No\n";
	return 0;
}