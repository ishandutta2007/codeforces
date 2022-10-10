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
#define OVER9000 1234567890123LL
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

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	string A;
	cin >> N >> A;
	vector< pair<int, int> > R;
	for(int i = 0; i < N; i++) if(i == 0 || A[i-1] == '0') if(A[i] == '1') {
		int r = i;
		while(r < N && A[r] == '1') r++;
		R.push_back({i, r-1});
	}
	int K = R.size();
	cat ans = 0;

	vector< pair<int, int> > S;
	vector<int> max_lim_l(K);
	for(int i = 0; i < K; i++) {
		int L = R[i].ss-R[i].ff+1;
		vector<int> lim_l(L+1, 0);
		for(int k = L, cur = -1; k >= 1; k--) {
			// closest >= k
			for(int b = 20; b >= 0; b--) if(cur+(1<<b) < (int)S.size()) {
				int L_nw = S[cur+(1<<b)].ss-S[cur+(1<<b)].ff+1;
				if(L_nw >= k) cur += 1<<b;
			}
			lim_l[k] = (cur == -1) ? 0 : (S[cur].ss-k+2);
			ans += 1LL * (R[i].ff-lim_l[k]) * k;
		}
		max_lim_l[i] = lim_l[L];
		while(!S.empty() && S.back().ss-S.back().ff+1 <= L) S.pop_back();
		S.push_back(R[i]);
	}

	S.clear();
	vector<int> max_lim_r(K);
	for(int i = K-1; i >= 0; i--) {
		int L = R[i].ss-R[i].ff+1;
		vector<int> lim_r(L+1, 0);
		for(int k = L, cur = -1; k >= 1; k--) {
			// closest >= k
			for(int b = 20; b >= 0; b--) if(cur+(1<<b) < (int)S.size()) {
				int L_nw = S[cur+(1<<b)].ss-S[cur+(1<<b)].ff+1;
				if(L_nw > k) cur += 1<<b;
			}
			lim_r[k] = (cur == -1) ? N-1 : (S[cur].ff+k-1);
			ans += 1LL * (lim_r[k]-R[i].ss) * k;
		}
		max_lim_r[i] = lim_r[L];
		while(!S.empty() && S.back().ss-S.back().ff+1 <= L) S.pop_back();
		S.push_back(R[i]);
	}

	for(int i = 0; i < K; i++) {
		int L = R[i].ss-R[i].ff+1;
		for(int j = 1; j <= L; j++) ans += 1LL * j * (L+1-j);
		ans += 1LL * (R[i].ff-max_lim_l[i]) * (max_lim_r[i]-R[i].ss) * L;
	}

	cout << ans << "\n";
}

// look at my code
// my code is amazing