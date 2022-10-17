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

const int MOD = 1000000007;

int binco[5005][5005];

int ans;
int best;

VI lef, rig;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	binco[0][0] = 1;
	REP(i, 1, 5001){
		binco[i][0] = 1;
		REP(j, 1, i+1){
			binco[i][j] = binco[i-1][j-1]+binco[i-1][j];
		}
	}
	int n, m;
	std::cin >> n >> m;
	VI S(n);
	FOR(i, n) std::cin >> S[i];
	std::map<int, VI> map;
	FOR(i, m){
		int f, h;
		std::cin >> f >> h;
		map[f].push_back(h);
	}
	std::map<int, int> ile;
	lef.resize(n+5);
	rig.resize(n+5);
	VI pre(n), suf(n);
	FOR(i, n){
		ile[S[i]]++;
		pre[i] = ile[S[i]];
	}
	ile = std::map<int, int>();
	for(int i = n-1; i >= 0; --i){
		ile[S[i]]++;
		suf[i] = ile[S[i]];
	}
	TRAV(pr, map) std::sort(pr.Y.begin(), pr.Y.end());
	ans = 0;
	best = 0;
	std::map<int, int> was;
	TRAV(pr, ile) rig[pr.X] = pr.Y;

	{
		int mam = 0;
		int ways = 1;
		TRAV(pr, map){
			int s = pr.X;
			int a = lef[s];
			int b = rig[s];
			if(a > b) std::swap(a, b);
			int l = std::upper_bound(pr.Y.begin(), pr.Y.end(), a)-pr.Y.begin();
			int r = std::upper_bound(pr.Y.begin(), pr.Y.end(), b)-pr.Y.begin();
			if(l == 0 && r == 0){

			}else if(l == 0){
				mam += 1;
				ways = (1ll*ways*r)%MOD;
			}else if(l == 1 && r == 1){
				mam += 1;
				ways = (ways+ways)%MOD;
			}else{
				mam += 2;
				ways = (1ll*ways*(r*l-l))%MOD;
			}
		}
		if(mam > best){
			best = mam;
			ans = ways;
		}else if(mam == best){
			ans = (ans+ways)%MOD;
		}

	}

	FOR(i, n){
		lef[S[i]]++;
		rig[S[i]]--;
		int s = S[i];
		int h = pre[i];
		VI &vec = map[s];
		if(std::binary_search(vec.begin(), vec.end(), h) == false) continue;
		int mam = 1;
		int ways = 1;
		int zostalo = rig[S[i]];
		int xd = 0;
		TRAV(j, vec) if(j <= zostalo && j != h) xd++;
		if(xd != 0) mam = 2, ways = xd;
		TRAV(pr, map){
			s = pr.X;
			if(s == S[i]) continue;
			int a = lef[s];
			int b = rig[s];
			if(a > b) std::swap(a, b);
			int l = std::upper_bound(pr.Y.begin(), pr.Y.end(), a)-pr.Y.begin();
			int r = std::upper_bound(pr.Y.begin(), pr.Y.end(), b)-pr.Y.begin();
			if(l == 0 && r == 0){

			}else if(l == 0){
				mam += 1;
				ways = (1ll*ways*r)%MOD;
			}else if(l == 1 && r == 1){
				mam += 1;
				ways = (ways+ways)%MOD;
			}else{
				mam += 2;
				ways = (1ll*ways*(r*l-l))%MOD;
			}
		}
		if(mam > best){
			best = mam;
			ans = ways;
		}else if(mam == best){
			ans = (ans+ways)%MOD;
		}
	}
	std::cout << best << " " << ans << std::endl;
	return 0;
}