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
	cin >> N;
	cout << ((N%2 == 0) ? "First" : "Second") << endl;
	if(N%2 == 0) {
		for(int i = 0; i < 2*N; i++) cout << (i%N+1) << ((i == 2*N-1) ? "" : " ");
		cout << endl;
		return 0;
	}
	vector<int> in_pair(2*N);
	vector< pair<int, int> > P(N, {-1, -1});
	for(int i = 0; i < 2*N; i++) {
		cin >> in_pair[i];
		in_pair[i]--;
		if(P[in_pair[i]].ff == -1) P[in_pair[i]].ff = i;
		else P[in_pair[i]].ss = i;
	}
	vector<char> used_p(N, 0), used_v(N, 0);
	vector< vector<int> > gr;
	int sum = 0;
	for(int i = 0; i < N; i++) if(!used_v[i]) {
		int cur_p = in_pair[i], other_v = P[in_pair[i]].ff+P[in_pair[i]].ss-i;
		used_v[i] = used_p[cur_p] = 1;
		vector<int> gr_cur = {i};
		other_v = (other_v+N) % (2*N);
		while(!used_p[in_pair[other_v]]) {
			int nxt_p = in_pair[other_v];
			int nxt_other_v = P[nxt_p].ff + P[nxt_p].ss - other_v;
			used_v[other_v%N] = used_p[nxt_p] = 1;
			gr_cur.push_back(other_v);
			cur_p = nxt_p;
			other_v = (nxt_other_v+N) % (2*N);
		}
		gr.push_back(gr_cur);
		for(auto x : gr_cur) {
			sum += x;
			if(sum >= 2*N) sum -= 2*N;
		}
	}
	if(sum%N != 0) return 1;
	vector<int> ans;
	for(auto vals : gr) {
		if(sum%(2*N) == 0 && vals.size()%2 != 0) {
			for(auto val : vals) ans.push_back((val+N)%(2*N));
			sum += N;
		}
		else for(auto val : vals) ans.push_back(val);
	}
	for(int i = 0; i < N; i++) cout << ans[i]+1 << ((i == N-1) ? "" : " ");
	cout << endl;
}

// look at my code
// my code is amazing