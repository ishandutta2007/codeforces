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

void upd(pair<int, int> & p, int old_val, int new_val) {
	if(old_val == p.ff) p.ff = new_val;
	else if(old_val == p.ss) {
		p.ss = new_val;
		if(p.ff > p.ss) swap(p.ff, p.ss);
	}
	else {
		if(new_val <= p.ss) p.ss = new_val;
		if(p.ff > p.ss) swap(p.ff, p.ss);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N), cnt_total(N, 0);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		cnt_total[--A[i]]++;
	}

	int SQ = 800;
	vector<int> id_large(N, -1);
	int n_large = 0;
	for(int i = 0; i < N; i++) if(cnt_total[i] >= SQ) id_large[i] = n_large++;
	vector< vector<int> > cnt(N+1, vector<int>(n_large, 0));
	vector< vector<int> > occ(n_large);
	for(int i = 0; i < N; i++) {
		cnt[i+1] = cnt[i];
		int id = id_large[A[i]];
		if(id == -1) continue;
		occ[id].push_back(i);
		cnt[i+1][id]++;
	}

	int ans = 0;
	vector<int> unique_mx(N, -1);
	for(int i = 0; i < N; i++) {
		int mx = 0;
		for(int j = 0; j < n_large; j++) mx = max(mx, cnt[i+1][j]);
		if(mx >= SQ) {
			int cnt_mx = 0;
			for(int j = 0; j < n_large; j++) if(mx == cnt[i+1][j]) cnt_mx++;
			if(cnt_mx > 1) ans = max(ans, i+1);
		}
		mx = 0;
		for(int j = 0; j < n_large; j++) mx = max(mx, cnt[N][j]-cnt[i][j]);
		if(mx >= SQ) {
			int cnt_mx = 0;
			for(int j = 0; j < n_large; j++) cnt_mx += (mx == cnt[N][j]-cnt[i][j]);
			if(cnt_mx > 1) ans = max(ans, N-i);
			else {
				for(int j = 0; j < n_large; j++)
					if(mx == cnt[N][j]-cnt[i][j]) unique_mx[i] = j;
			}
		}
		else unique_mx[i] = -2;
	}

	for(int v = 0; v < n_large; v++) {
		vector<int> B;
		for(int i = N-1; i > 0; i--)
			if(unique_mx[i] == v || id_large[A[i]] == v) B.push_back(i);
		vector<int> last(2*N+1, -1);
		for(int u = 0; u < n_large; u++) if(u != v) for(auto i : B) {
			if(unique_mx[i] == v && id_large[A[i-1]] != -1)
				ans = max(ans, last[cnt[i][v]-cnt[i][u]+N]-u*N-i);
			if(id_large[A[i]] == v) {
				int x = cnt[i][v]-cnt[i][u]+N;
				if(last[x] <= u*N-1) last[x] = u*N+i;
			}
		}
	}

	vector< vector<int> > close_val(N);
	vector< pair<int, int> > min_close_val(SQ+1, {N, N});
	for(int i = N-1; i >= 0; i--) {
		int sz = close_val[A[i]].size();
		close_val[A[i]].push_back(N);
		for(int f = sz; f > 0; f--) {
			upd(min_close_val[f], close_val[A[i]][f], close_val[A[i]][f-1]);
			close_val[A[i]][f] = close_val[A[i]][f-1];
		}
		upd(min_close_val[0], close_val[A[i]][0], i);
		close_val[A[i]][0] = i;
		if(sz == SQ) close_val[A[i]].pop_back();
		for(int f = 1; f < SQ; f++)
			if(min_close_val[f-1].ss < min_close_val[f].ff)
				ans = max(ans, min_close_val[f].ff-i);
	}

	cout << ans << "\n";
}

// look at my code
// my code is amazing