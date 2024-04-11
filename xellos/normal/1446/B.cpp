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
	int N[2];
	string S[2];
	cin >> N[0] >> N[1] >> S[0] >> S[1];
	vector< vector<int> > max_cost(N[0]+1, vector<int>(N[1]+1, 0));
	for(int i = 0; i < N[0]; i++) for(int j = 0; j < N[1]; j++) {
		max_cost[i+1][j] = max(max_cost[i+1][j], max_cost[i][j]-1);
		max_cost[i][j+1] = max(max_cost[i][j+1], max_cost[i][j]-1);
		if(S[0][i] == S[1][j])
			max_cost[i+1][j+1] = max(max_cost[i+1][j+1], max_cost[i][j]+2);
	}
	int ans = 0;
	for(int i = 0; i <= N[0]; i++) for(int j = 0; j <= N[1]; j++)
		ans = max(ans, max_cost[i][j]);
	cout << ans << "\n";
}

// look at my code
// my code is amazing