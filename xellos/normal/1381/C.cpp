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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, X, Y;
		cin >> N >> X >> Y;
		Y -= X;
		vector< vector<int> > pos(N+1);
		for(int i = 0; i < N; i++) {
			int c;
			cin >> c;
			pos[--c].push_back(i);
		}
		vector<int> A(N);
		for(int i = 0; i <= N; i++) if(pos[i].empty()) {
			for(int j = 0; j < N; j++) A[j] = i;
			break;
		}
		priority_queue< pair<int, int> > by_occ;
		for(int i = 0; i <= N; i++) by_occ.push({pos[i].size(), i});
		for(int i = 0; i < X; i++) {
			auto p = by_occ.top();
			by_occ.pop();
			A[pos[p.ss].back()] = p.ss;
			pos[p.ss].pop_back();
			by_occ.push({pos[p.ss].size(), p.ss});
		}
		while(Y) {
			static vector<int> max_occ;
			max_occ.clear();
			int max_occ_val = by_occ.top().ff;
			while(!by_occ.empty() && by_occ.top().ff == max_occ_val) {
				max_occ.push_back(by_occ.top().ss);
				by_occ.pop();
			}
			if((int)max_occ.size() == 1 && !by_occ.empty() && by_occ.top().ff) {
				max_occ.push_back(by_occ.top().ss);
				by_occ.pop();
			}
			if((int)max_occ.size() == 1) break;
			for(int i = 0; i < (int)max_occ.size(); i++) if(Y) {
				A[pos[max_occ[i]].back()] = max_occ[(i+1)%max_occ.size()];
				pos[max_occ[i]].pop_back();
				Y--;
			}
			for(auto v : max_occ) by_occ.push({pos[v].size(), v});
		}
		if(Y) cout << "NO\n";
		else {
			cout << "YES\n";
			for(int i = 0; i < N; i++) cout << A[i]+1 << ((i == N-1) ? "\n" : " ");
		}
	}
}

// look at my code
// my code is amazing