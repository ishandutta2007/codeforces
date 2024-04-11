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

void solve(auto & A, vector<int> ids, auto & ans) {
	if(ids.empty()) return;
	int min_id = ids[0];
	for(auto id : ids) if(A[id] < A[min_id]) min_id = id;
	vector<int> ids_nw;
	ids_nw.dibs(ids.size());
	for(auto id : ids) if(id != min_id) ids_nw.push_back(id);
	solve(A, ids_nw, ans);
	for(auto id : ids) {
		if(id == min_id) break;
		ans.push_back({id, min_id});
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<int> ids(N);
	for(int i = 0; i < N; i++) ids[i] = i;
	vector< pair<int, int> > ans;
	solve(A, ids, ans);
	cout << ans.size() << "\n";
	for(auto p : ans) cout << p.ff+1 << " " << p.ss+1 << "\n";
}

// look at my code
// my code is amazing