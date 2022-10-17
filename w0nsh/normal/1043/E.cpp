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

int n, m;
std::vector<VI> g;
std::vector<PII> A;
std::vector<ll> sum;
// 0 - first smaller
// 1 - second smaller
ll sum_smaller[2];
int count_smaller[2];
std::vector<PII> sor[2];
std::vector<ll> pref[2][2];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	g.resize(n);
	sum.resize(n);
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		A.push_back(MP(a, b));
	}
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	FOR(i, n){
		if(A[i].X < A[i].Y){
			sum_smaller[0] += A[i].X;
			count_smaller[0]++;
			sor[0].push_back(MP(A[i].Y-A[i].X, i));
		}else{
			count_smaller[1]++;
			sum_smaller[1] += A[i].Y;
			sor[1].push_back(MP(A[i].X-A[i].Y, i));
		}
	}
	FOR(i, 2) std::sort(sor[i].begin(), sor[i].end());
	FOR(i, 2) FOR(j, 2) pref[i][j].resize(SZ(sor[i])+1);
	FOR(kt, 2) FOR(i, SZ(sor[kt])) pref[kt][0][i+1] = pref[kt][0][i]
								+ std::min(A[sor[kt][i].Y].X, A[sor[kt][i].Y].Y);
	FOR(kt, 2) FOR(i, SZ(sor[kt])) pref[kt][1][i+1] = pref[kt][1][i]
								+ std::max(A[sor[kt][i].Y].X, A[sor[kt][i].Y].Y);
	//FOR(i, n+1) std::cout << pref[0][0][i] << " ";
	//std::cout << "\n";
	FOR(i, n){
		//std::cout << "\n" << i << ":\n";
		// 0 first smaller
		int which = (A[i].X < A[i].Y ? 0 : 1);
		// all simple
		ll cur = sum_smaller[(which+1)%2] + 1ll*count_smaller[(which+1)%2]*std::min(A[i].X, A[i].Y);
		//std::cout << "sumple adding " << cur << "\n";
		// not simple
		auto &sr = sor[which];
		int ind = std::distance(sr.begin(), std::lower_bound(sr.begin(), sr.end(), MP(std::abs(A[i].X-A[i].Y), i)));
		//std::cout << "ind " << ind << "\n";
		cur += pref[which][0][SZ(sr)] - pref[which][0][ind+1];
		//std::cout << "adding " << pref[which][0][SZ(sr)] - pref[which][0][ind+1] << ", " << 1ll*(SZ(sr)-ind-2)*std::max(A[i].X, A[i].Y) << "\n";
		cur += 1ll*(SZ(sr)-ind-1)*std::max(A[i].X, A[i].Y);
		cur += pref[which][1][ind];
		//std::cout << "adding " << pref[which][1][ind] << "," << 1ll*(ind)*std::min(A[i].X, A[i].Y) << "\n";
		cur += 1ll*(ind)*std::min(A[i].X, A[i].Y);
		// graph
		TRAV(ch, g[i]){
			cur -= std::min(A[i].X+A[ch].Y, A[i].Y+A[ch].X);
		}
		std::cout << cur << " ";
	}
	return 0;
}