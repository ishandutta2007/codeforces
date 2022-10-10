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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, K;
		cin >> N >> K;
		if(N == 1) {
			int a;
			cin >> a;
			cout << ((a == K) ? "yes\n" : "no\n");
			continue;
		}
		vector<int> A(N);
		bool has_occ = false;
		for(int i = 0; i < N; i++) {
			cin >> A[i];
			has_occ |= (A[i] == K);
			A[i] = (A[i] >= K) ? 1 : -1;
		}
		if(!has_occ) {
			cout << "no\n";
			continue;
		}
		// positive sum?
		vector<int> S(N+1, 0);
		for(int i = 0; i < N; i++) S[i+1] = S[i] + A[i];
		bool ans = false;
		for(int i = 1, cur = 0; i < N; i++) {
			if(S[i+1] > cur) ans = true;
			cur = min(cur, S[i]);
		}
		cout << (ans ? "yes\n" : "no\n");
	}
	return 0;
}

// look at my code
// my code is amazing