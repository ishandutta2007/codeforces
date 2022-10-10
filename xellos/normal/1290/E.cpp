// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct fin {
	vector<int> T;
	fin(int N) : T(N+1, 0) {}

	int lastone(int x) {return x & (x ^ (x-1));}

	void put(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i))
			T[i] += val; 
	}

	int get(int pos) {
		int ret = 0;
		for(int i = pos+1; i; i -= lastone(i)) ret += T[i];
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N), pos(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		pos[--A[i]] = i;
	}
	vector<cat> ans(N, 0);
	for(int k = 0; k < 2; k++) {
		reverse(begin(A), end(A));
		for(int i = 0; i < N; i++) pos[A[i]] = i;
		fin F(N);
		constexpr int K = 300;
		int B = N/K+1;
		vector< vector< pair<int, int> > > bl(B);
		vector< vector<int> > last_ids(B);
		vector<int> last_val(B), add(B, 0);
		vector<cat> sum(B, 0);
		for(int i = 0; i < N; i++) {
			int p = pos[i];
			int val = F.get(p);
			F.put(p, 1);
			int id = p/K;

			static vector< pair<int, int> > bl_low;
			bl_low.clear();
			static vector< pair<int, int> > bl_hi;
			bl_hi.clear();
			for(auto pp : bl[id]) {
				pp.ff += add[id];
				if(pp.ss < p) bl_low.push_back({min(pp.ff, val), pp.ss});
				else bl_hi.push_back({pp.ff+1, pp.ss});
			}
			last_val[id] += add[id];
			for(auto x : last_ids[id]) {
				if(x < p) bl_low.push_back({min(last_val[id], val), x});
				else bl_hi.push_back({last_val[id]+1, x});
			}
			bl[id].clear();
			merge(begin(bl_low), end(bl_low), begin(bl_hi), end(bl_hi), back_inserter(bl[id]));
			bl[id].push_back({i+1, p});
			for(int j = (int)bl[id].size()-2; j >= 0; j--) {
				if(bl[id][j].ff > bl[id][j+1].ff) swap(bl[id][j], bl[id][j+1]);
				else break;
			}
			last_ids[id].clear();
			add[id] = sum[id] = 0;
			for(auto pp : bl[id]) sum[id] += pp.ff;

			for(int j = id+1; j < B; j++) {
				add[j]++;
				sum[j] += last_ids[j].size()+bl[j].size();
			}

			for(int j = 0; j < id; j++) {
				int v = val - add[j];
				if(!last_ids[j].empty() && last_val[j] <= v) continue;
				sum[j] -= 1LL * (last_val[j]-v) * last_ids[j].size();
				last_val[j] = min(last_val[j], v);
				if(last_ids[j].empty()) {
					if(bl[j].empty()) continue;
					int x = bl[j].back().ff;
					if(x < v) continue;
					sum[j] += v-x;
					last_val[j] = v;
					last_ids[j].push_back(bl[j].back().ss);
					bl[j].pop_back();
				}
				while(!bl[j].empty()) {
					int x = bl[j].back().ff;
					if(x < last_val[j]) break;
					sum[j] += last_val[j]-x;
					last_ids[j].push_back(bl[j].back().ss);
					bl[j].pop_back();
				}
			}

			for(int j = 0; j <= N/K; j++) ans[i] += sum[j];
		}
	}
	for(int i = 0; i < N; i++) cout << ans[i]-(i+1LL)*(i+1) << "\n";
	return 0;
}

// look at my code
// my code is amazing