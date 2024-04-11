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
		int N[3];
		cin >> N[0] >> N[1] >> N[2];
		vector<cat> A[3];
		for(int k = 0; k < 3; k++) {
			A[k].resize(N[k]);
			for(int i = 0; i < N[k]; i++) cin >> A[k][i];
			sort(begin(A[k]), end(A[k]));
		}
		cat ans = (A[0][0]-A[1][0])*(A[0][0]-A[1][0])+(A[1][0]-A[2][0])*(A[1][0]-A[2][0])+(A[2][0]-A[0][0])*(A[2][0]-A[0][0]);
		for(int k = 0; k < 3; k++) {
			vector<cat> B[2];
			if(k == 0) B[0] = A[1], B[1] = A[2];
			else B[0] = A[0], B[1] = A[3-k];
			for(auto v : A[k]) {
				auto it = lower_bound(begin(B[0]), end(B[0]), v);
				if(it == end(B[0])) break;
				auto jt = upper_bound(begin(B[1]), end(B[1]), v);
				if(jt == begin(B[1])) continue;
				jt--;
				ans = min(ans, (v-*it)*(v-*it)+(v-*jt)*(v-*jt)+(*it-*jt)*(*it-*jt));
			}
			swap(B[0], B[1]);
			for(auto v : A[k]) {
				auto it = lower_bound(begin(B[0]), end(B[0]), v);
				if(it == end(B[0])) break;
				auto jt = upper_bound(begin(B[1]), end(B[1]), v);
				if(jt == begin(B[1])) continue;
				jt--;
				ans = min(ans, (v-*it)*(v-*it)+(v-*jt)*(v-*jt)+(*it-*jt)*(*it-*jt));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing