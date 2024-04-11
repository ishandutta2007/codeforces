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
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		map<int, vector<int> > occ;
		for(int i = 0; i < N; i++) {
			int a;
			cin >> a;
			auto it = occ.find(a);
			if(it == end(occ)) occ[a] = {-1, i};
			else (it->ss).push_back(i);
		}
		vector<int> ans(N+1, N+10);
		for(auto p : occ) {
			auto v = p.ss;
			v.push_back(N);
			int d = 0;
			for(int i = 1; i < (int)v.size(); i++) d = max(d, v[i]-v[i-1]);
			ans[d] = min(ans[d], p.ff);
		}
		for(int i = 1; i <= N; i++) ans[i] = min(ans[i], ans[i-1]);
		for(int i = 1; i <= N; i++) cout << ((ans[i] > N) ? -1 : ans[i]) << ((i == N) ? "\n" : " ");
	}
}

// look at my code
// my code is amazing