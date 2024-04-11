// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

struct triv {vector< pair<dbl, dbl> > L, R, C;};

triv splith(vector< pair<int, int> > L0, vector< pair<int, int> > R0) {
	vector< pair<dbl, dbl> > L = {{L0[0].ff, L0[0].ss}}, R = {{L0[0].ff, L0[0].ss}};
	int l = 0, r = 0, sz_l = L0.size(), sz_r = R0.size();
	while(l < sz_l-2 || r < sz_r-2) {
		if(L0[l+1].ss < R0[r+1].ss) {
			L.push_back({L0[l+1].ff, L0[l+1].ss});
			R.push_back({R.back().ff+(L0[l+1].ss-R.back().ss)/(R0[r+1].ss-R.back().ss)*(R0[r+1].ff-R.back().ff), L0[l+1].ss});
			l++;
		}
		else if(L0[l+1].ss > R0[r+1].ss) {
			R.push_back({R0[r+1].ff, R0[r+1].ss});
			L.push_back({L.back().ff+(R0[r+1].ss-L.back().ss)/(L0[l+1].ss-L.back().ss)*(L0[l+1].ff-L.back().ff), R0[r+1].ss});
			r++;
		}
		else {
			L.push_back({L0[l+1].ff, L0[l+1].ss});
			R.push_back({R0[r+1].ff, R0[r+1].ss});
			l++, r++;
		}
	}
	L.push_back({L0[sz_l-1].ff, L0[sz_l-1].ss});
	R.push_back({R0[sz_r-1].ff, R0[sz_r-1].ss});
	if(L[1].ff > R[1].ff) swap(L, R);
	vector< pair<dbl, dbl> > C;
	for(int i = 0; i < (int)L.size(); i++) C.push_back({(L[i].ff+R[i].ff)/2, L[i].ss});
	return {L, R, C};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	cin >> N >> Q;
	vector< pair<int, int> > P(N);
	for(int i = 0; i < N; i++) cin >> P[i].ff >> P[i].ss;
	int mx = 0, mi = 0;
	for(int i = 0; i < N; i++) if(P[i].ss < P[mi].ss) mi = i;
	for(int i = 0; i < N; i++) if(P[i].ss > P[mx].ss) mx = i;
	vector< pair<int, int> > L0, R0;
	for(int i = mi; i != mx; i = (i+1)%N) L0.push_back(P[i]);
	L0.push_back(P[mx]);
	for(int i = mi; i != mx; i = (i+N-1)%N) R0.push_back(P[i]);
	R0.push_back(P[mx]);
	auto [L, R, C] = splith(L0, R0);

	vector< pair<int, int> > qu(Q);
	for(int i = 0; i < Q; i++) {
		cin >> qu[i].ff;
		qu[i].ss = i;
	}
	sort(begin(qu), end(qu));
	vector< pair<dbl, dbl> > ans(Q, {0, 0});

	{
		dbl c_quad = 0, c_lin = 0, c_const = 0;
		vector< pair<dbl, int> > bound_add, bound_sub;
		for(int i = 1; i < (int)L.size(); i++) {
			bound_sub.push_back({min(L[i].ff, L[i-1].ff), 2*i});
			bound_sub.push_back({max(L[i].ff, L[i-1].ff), 2*i+1});
		}
		for(int i = 1; i < (int)C.size(); i++) {
			bound_add.push_back({min(C[i].ff, C[i-1].ff), 2*i});
			bound_add.push_back({max(C[i].ff, C[i-1].ff), 2*i+1});
		}
		sort(begin(bound_add), end(bound_add));
		sort(begin(bound_sub), end(bound_sub));
		for(int i = 0, a = 0, b = 0; i < Q; i++) {
			while(a < (int)bound_add.size() && bound_add[a].ff < qu[i].ff) {
				int id = bound_add[a].ss/2, tp = bound_add[a].ss%2;
				a++;
				dbl dy = C[id].ss-C[id-1].ss;
				dbl xl = min(C[id-1].ff, C[id].ff);
				dbl xr = max(C[id-1].ff, C[id].ff);
				if(tp == 0 && xr-xl > soclose) {
					c_quad += dy/2./(xr-xl);
					c_const += xl*xl*dy/2./(xr-xl);
					c_lin -= xl*dy/(xr-xl);
				}
				if(tp == 1 && xr-xl > soclose) {
					c_quad -= dy/2./(xr-xl);
					c_const -= xl*xl*dy/2./(xr-xl);
					c_lin += xl*dy/(xr-xl);
					c_const += (xr-xl)*dy/2.;
				}
				if(tp == 1) {
					c_lin += dy;
					c_const -= dy*xr;
				}
			}
			while(b < (int)bound_sub.size() && bound_sub[b].ff < qu[i].ff) {
				int id = bound_sub[b].ss/2, tp = bound_sub[b].ss%2;
				b++;
				dbl dy = L[id].ss-L[id-1].ss;
				dbl xl = min(L[id-1].ff, L[id].ff);
				dbl xr = max(L[id-1].ff, L[id].ff);
				if(tp == 0 && xr-xl > soclose) {
					c_quad -= dy/2./(xr-xl);
					c_const -= xl*xl*dy/2./(xr-xl);
					c_lin += xl*dy/(xr-xl);
				}
				if(tp == 1 && xr-xl > soclose) {
					c_quad += dy/2./(xr-xl);
					c_const += xl*xl*dy/2./(xr-xl);
					c_lin -= xl*dy/(xr-xl);
					c_const -= (xr-xl)*dy/2.;
				}
				if(tp == 1) {
					c_lin -= dy;
					c_const += dy*xr;
				}
			}
			ans[qu[i].ss].ff = (c_quad*qu[i].ff+c_lin)*qu[i].ff+c_const;
		}
	}

	{
		dbl c_quad = 0, c_lin = 0, c_const = 0;
		vector< pair<dbl, int> > bound_add, bound_sub;
		for(int i = 1; i < (int)C.size(); i++) {
			bound_sub.push_back({min(C[i].ff, C[i-1].ff), 2*i});
			bound_sub.push_back({max(C[i].ff, C[i-1].ff), 2*i+1});
		}
		for(int i = 1; i < (int)R.size(); i++) {
			bound_add.push_back({min(R[i].ff, R[i-1].ff), 2*i});
			bound_add.push_back({max(R[i].ff, R[i-1].ff), 2*i+1});
		}
		sort(begin(bound_add), end(bound_add));
		sort(begin(bound_sub), end(bound_sub));
		for(int i = 0, a = 0, b = 0; i < Q; i++) {
			while(a < (int)bound_add.size() && bound_add[a].ff < qu[i].ff) {
				int id = bound_add[a].ss/2, tp = bound_add[a].ss%2;
				a++;
				dbl dy = R[id].ss-R[id-1].ss;
				dbl xl = min(R[id-1].ff, R[id].ff);
				dbl xr = max(R[id-1].ff, R[id].ff);
				if(tp == 0 && xr-xl > soclose) {
					c_quad += dy/2./(xr-xl);
					c_const += xl*xl*dy/2./(xr-xl);
					c_lin -= xl*dy/(xr-xl);
				}
				if(tp == 1 && xr-xl > soclose) {
					c_quad -= dy/2./(xr-xl);
					c_const -= xl*xl*dy/2./(xr-xl);
					c_lin += xl*dy/(xr-xl);
					c_const += (xr-xl)*dy/2.;
				}
				if(tp == 1) {
					c_lin += dy;
					c_const -= dy*xr;
				}
			}
			while(b < (int)bound_sub.size() && bound_sub[b].ff < qu[i].ff) {
				int id = bound_sub[b].ss/2, tp = bound_sub[b].ss%2;
				b++;
				dbl dy = C[id].ss-C[id-1].ss;
				dbl xl = min(C[id-1].ff, C[id].ff);
				dbl xr = max(C[id-1].ff, C[id].ff);
				if(tp == 0 && xr-xl > soclose) {
					c_quad -= dy/2./(xr-xl);
					c_const -= xl*xl*dy/2./(xr-xl);
					c_lin += xl*dy/(xr-xl);
				}
				if(tp == 1 && xr-xl > soclose) {
					c_quad += dy/2./(xr-xl);
					c_const += xl*xl*dy/2./(xr-xl);
					c_lin -= xl*dy/(xr-xl);
					c_const -= (xr-xl)*dy/2.;
				}
				if(tp == 1) {
					c_lin -= dy;
					c_const += dy*xr;
				}
			}
			ans[qu[i].ss].ss = (c_quad*qu[i].ff+c_lin)*qu[i].ff+c_const;
		}
	}

	dbl A = 0;
	for(int i = 1; i < N-1; i++)
		A += 1LL * (P[i].ff-P[0].ff) * (P[i+1].ss-P[0].ss) - 1LL * (P[i].ss-P[0].ss) * (P[i+1].ff-P[0].ff);
	if(A < 0) A = -A;
	for(int i = 0; i < Q; i++) cout << A/2-abs(ans[i].ff-ans[i].ss) << "\n";
}

// look at my code
// my code is amazing