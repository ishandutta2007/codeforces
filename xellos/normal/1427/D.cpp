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
	vector<int> C(N);
	for(int i = 0; i < N; i++) {
		cin >> C[i];
		C[i]--;
	}
	vector< vector<int> > ans;
	while(true) {
		bool stop = true;
		for(int i = 0; i < N; i++) if(stop) for(int j = i+1; j < N; j++) if(C[j] == C[i]-1) {
			stop = false;
			int l = j;
			while(C[l-1] == C[l]-1) l--;
			l--;
			vector<int> v = {i, l+1-i, j-l, N-j-1};
			vector<int> C_nw;
			for(int k = j+1; k < N; k++) C_nw.push_back(C[k]);
			for(int k = l+1; k <= j; k++) C_nw.push_back(C[k]);
			for(int k = i; k <= l; k++) C_nw.push_back(C[k]);
			for(int k = 0; k < i; k++) C_nw.push_back(C[k]);
			C = C_nw;
			vector<int> vz;
			for(auto x : v) if(x) vz.push_back(x);
			ans.push_back(vz);
			break;
		}
		if(stop) break;
	}
	cout << ans.size() << "\n";
	for(auto & v : ans) {
		cout << v.size();
		for(int i = 0; i < (int)v.size(); i++) cout << " " << v[i];
		cout << "\n";
	}
}

// look at my code
// my code is amazing