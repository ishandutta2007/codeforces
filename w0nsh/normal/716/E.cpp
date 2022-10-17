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

int n, M, inv;
ll ans;
std::vector<std::vector<PII> > g;

int modpow(int a, int e){
	int ret = 1;
	int cur = a;
	while(e > 0){
		if(e & 1) ret = (1ll*ret*cur)%M;
		cur = (1ll*cur*cur)%M;
		e >>= 1;
	}
	return ret;
}

void calc_inverse(){
	int cur = 2;
	int have = M;
	int tot = 1;
	while(have > 1 && cur*cur <= M){
		int cnt = 0;
		while(have % cur == 0) have /= cur, cnt++;
		if(cnt > 0){
			tot *= modpow(cur, cnt-1)*(cur-1);
		}
		cur++;
	}
	if(have > 1) tot *= (have-1);
	inv = modpow(10, tot-1);
}

VI size;
std::vector<bool> block;

int rozm(int v, int par=-1){
	int ret = 1;
	TRAV(ch, g[v]){
		if(block[ch.X] || ch.X == par) continue;
		ret += rozm(ch.X, v);
	}
	return ret;
}

int centroid(int v, int par, int all){
	bool ths = true;
	size[v] = 1;
	TRAV(ch, g[v]){
		if(block[ch.X] || ch.X == par) continue;
		int xd = centroid(ch.X, v, all);
		if(xd != -1) return xd;
		if(size[ch.X] > all/2) ths = false;
		size[v] += size[ch.X];
	}
	if(all-size[v] > all/2) ths = false;
	if(ths) return v;
	return -1;
}

void getup(int v, int par, int cur, int dep, std::map<int, int> &map){
	map[cur]++;
	TRAV(ch, g[v]){
		if(block[ch.X] || ch.X == par) continue;
		int wth = (1ll*cur + 1ll*ch.Y*modpow(10, dep))%M;
		getup(ch.X, v, wth, dep+1, map);
	}
}

void getdown(int v, int par, int cur, int dep, std::map<int, int> &map){
	// std::cout << "entering " << v << std::endl;
	int want = (1ll*-cur * modpow(inv, dep))%M;
	if(want < 0) want += M;
	auto xd = map.find(want);
	if(xd != map.end()) ans += xd->Y;
	// if(xd != map.end()) std::cout << "down " << cur << " found " << xd->Y << std::endl;
	TRAV(ch, g[v]){
		if(block[ch.X] || ch.X == par) continue;
		getdown(ch.X, v, (10ll*cur+ch.Y)%M, dep+1, map);
	}
	// std::cout << "leaving " << v << std::endl;
}

void rec(int v){
	int all = rozm(v);
	if(all == 1){
		block[v] = true;
		return;
	}
	int cent = centroid(v, -1, all);

	std::map<int, int> map;
	std::map<int, std::map<int, int> > chi;
	TRAV(ch, g[cent]){
		if(block[ch.X]) continue;
		chi[ch.X] = std::map<int, int>();
		getup(ch.X, cent, ch.Y%M, 1, chi[ch.X]);
		TRAV(i, chi[ch.X]) map[i.X] += i.Y;
	}
	ans += map[0]; // tylko w gore
	map[0]++; // tylko w dol
	TRAV(ch, g[cent]){
		if(block[ch.X]) continue;
		TRAV(i, chi[ch.X]) map[i.X] -= i.Y;
		getdown(ch.X, cent, ch.Y%M, 1, map);
		TRAV(i, chi[ch.X]) map[i.X] += i.Y;
	}

	// std::cout << "cent " << cent << " ans " << ans << std::endl;
	block[cent] = true;
	TRAV(ch, g[cent]){
		if(block[ch.X]) continue;
		rec(ch.X);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> M;
	calc_inverse();
	g.resize(n);
	size.resize(n);
	block.resize(n);
	FOR(i, n-1){
		int a, b, c;
		std::cin >> a >> b >> c;
		g[a].push_back(MP(b, c));
		g[b].push_back(MP(a, c));
	}
	rec(0);
	std::cout << ans;
	return 0;
}