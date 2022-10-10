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
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

constexpr cat mod = 1000000007;

cat pw(cat a, cat e) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, P;
		cin >> N >> P;
		vector<int> E(N);
		for(int i = 0; i < N; i++) cin >> E[i];
		sort(begin(E), end(E));
		vector< pair<int, int> > E_occ;
		for(int i = 0; i < N; i++) if(i == 0 || E[i] != E[i-1]) {
			int cnt = 0;
			for(int j = i; j < N; j++) {
				if(E[i] == E[j]) cnt++;
				else break;
			}
			E_occ.push_back({cnt, E[i]});
		}
		int K = E_occ.size();
		cat d = 0, cur_e = E_occ[K-1].ss;
		bool large = false;
		for(int i = K-1; i >= 0; i--) {
			if(d == 0 || P == 1) cur_e = E_occ[i].ss;
			while(cur_e != E_occ[i].ss && d <= N && !large) {
				d *= P;
				cur_e--;
				if(d > N) break;
			}
			if(!large && d > N) large = true;
			if(large) {
				d = d % mod * pw(P, cur_e-E_occ[i].ss) % mod;
				cur_e = E_occ[i].ss;
				d -= E_occ[i].ff;
				if(d < 0) d += mod;
				continue;
			}
			if(d >= E_occ[i].ff) d -= E_occ[i].ff;
			else d = (d+E_occ[i].ff)%2;
		}
		d = d * pw(P, cur_e) % mod;
		cout << d << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing