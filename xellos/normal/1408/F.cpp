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
	cin >> N;
	vector< vector<int> > S(N);
	set< pair<int, int> > st;
	int n = N;
	vector< pair<int, int> > ans;
	while(n) {
		int bb = 1;
		while(2*bb <= n) bb *= 2;
		vector< vector<int> > S_cur(bb);
		set< pair<int, int> > st_cur;
		for(int i = n-1; i >= n-bb; i--) {
			S_cur[n-1-i] = {i};
			st_cur.insert({1, n-1-i});
		}
		n -= bb;
		while((int)st_cur.size() > 1) {
			int m = begin(st_cur)->ff;
			auto it = begin(st_cur);
			it++;
			int nw = S_cur.size();
			int a = begin(st_cur)->ss, b = it->ss;
			S_cur.push_back({});
			for(int i = 0; i < m; i++) {
				ans.push_back({S_cur[a][i], S_cur[b][i]});
				S_cur[nw].push_back(S_cur[a][i]);
				S_cur[nw].push_back(S_cur[b][i]);
			}
			S_cur[a].clear();
			S_cur[b].clear();
			st_cur.erase(begin(st_cur));
			st_cur.erase(it);
			st_cur.insert({2*m, nw});
		}
		st.insert({bb, S.size()});
		S.push_back(S_cur[begin(st_cur)->ss]);
	}
	while((int)st.size() > 2) {
		int m = begin(st)->ff;
		auto it = begin(st);
		it++;
		int nw = S.size();
		S.push_back({});
		if(it->ff == m) {
			int a = begin(st)->ss, b = it->ss;
			for(int i = 0; i < m; i++) {
				ans.push_back({S[a][i], S[b][i]});
				S[nw].push_back(S[a][i]);
				S[nw].push_back(S[b][i]);
			}
			S[a].clear();
			S[b].clear();
			st.erase(begin(st));
			st.erase(it);
			st.insert({2*m, nw});
		}
		else {
			int a = begin(st)->ss, b = rbegin(st)->ss;
			for(int i = 0; i < m; i++) {
				ans.push_back({S[a][i], S[b].back()});
				S[nw].push_back(S[a][i]);
				S[nw].push_back(S[b].back());
				S[b].pop_back();
			}
			S[a].clear();
			int M = rbegin(st)->ff;
			st.erase(--end(st));
			st.erase(begin(st));
			st.insert({M-m, b});
			st.insert({2*m, nw});
		}
	}
	cout << (int)ans.size() << "\n";
	for(auto p : ans) cout << p.ff+1 << " " << p.ss+1 << "\n";
}

// look at my code
// my code is amazing