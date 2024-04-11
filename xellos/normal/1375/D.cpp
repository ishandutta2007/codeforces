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
		int N;
		cin >> N;
		vector<int> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		vector<int> occ(N+1, 0);
		for(int i = 0; i < N; i++) occ[A[i]]++;
		int R = N;
		vector<int> ops;
		while(true) {
			bool sorted = true;
			for(int i = 0; i < N-1; i++) if(A[i] > A[i+1]) sorted = false;
			if(sorted) break;
			int mex = 0;
			while(occ[mex]) mex++;
			if(mex == R) {
				occ[A[R-1]]--;
				A[R-1] = mex;
				ops.push_back(R-1);
				occ[mex]++;
				R--;
			}
			else {
				occ[A[mex]]--;
				A[mex] = mex;
				ops.push_back(mex);
				occ[mex]++;
			}
		}
		cout << ops.size() << "\n";
		for(int i = 0; i < (int)ops.size(); i++)
			cout << ops[i]+1 << ((i+1 == (int)ops.size()) ? "\n" : " ");
	}
}

// look at my code
// my code is amazing