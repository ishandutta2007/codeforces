#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int ILE = 1000;

int mex(VI &a){
	int xd = 0;
	while(std::find(a.begin(), a.end(), xd) != a.end()) xd++;
	return xd;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int x, y, z, n;
		std::cin >> n >> x >> y >> z;
		std::vector<ll> A(n);
		FOR(i, n) std::cin >> A[i];
		VI grund(3*ILE);
		REP(i, 1, ILE){
			VI mam;
			mam.push_back(grund[std::max(0, (i-x)*3)]);
			mam.push_back(grund[std::max(0, (i-y)*3+1)]);
			mam.push_back(grund[std::max(0, (i-z)*3+2)]);
			grund[i*3] = mex(mam);
			mam.clear();
			mam.push_back(grund[std::max(0, (i-x)*3)]);
			mam.push_back(grund[std::max(0, (i-z)*3+2)]);
			grund[i*3+1] = mex(mam);
			mam.clear();
			mam.push_back(grund[std::max(0, (i-x)*3)]);
			mam.push_back(grund[std::max(0, (i-y)*3+1)]);
			grund[i*3+2] = mex(mam);
		}
//		FOR(i, 100) std::cout << grund[i*3] << " ";
//		std::cout << std::endl;
//		std::cin >> xr;
		std::map<VI, int> map;
		int cyc = -1;
		int siz = -1;
		FOR(i, ILE){
			VI xd;
			FOR(j, 15){
				xd.push_back(grund[i+j]);
			}
			if(map.count(xd)){
				siz = i-map[xd];
				cyc = map[xd];
				break;
			}
			map[xd] = i;
		}
		assert(cyc != -1);
		auto ind = [&](ll a){
			if(a < cyc) return (int)a;
			return (int)(cyc+(a-cyc)%siz);
		};
		int xr = 0;
		FOR(i, n) xr ^= grund[ind(A[i]*3)];
		int ans = 0;
		FOR(i, n){
			int cur = xr^grund[ind(A[i]*3)];
			if((cur^grund[ind(std::max(0ll, (A[i]-x)*3))]) == 0) ans++;
			if((cur^grund[ind(std::max(0ll, (A[i]-y)*3+1))]) == 0) ans++;
			if((cur^grund[ind(std::max(0ll, (A[i]-z)*3+2))]) == 0) ans++;
		}
		std::cout << ans << "\n";
	}

	return 0;
}