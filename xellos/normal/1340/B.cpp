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
	int dig[10] = {0b1110111, 0b0100100, 0b1011101,
		0b1101101, 0b0101110, 0b1101011, 0b1111011,
		0b0100101, 0b1111111, 0b1101111};
	int N, K;
	cin >> N >> K;
	vector<int> A(N, 0);
	for(int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for(int j = 0; j < 7; j++) if(S[j] == '1') A[i] += (1<<j);
	}
	vector< vector<char> > dp(N+1, vector<char>(K+1, 0));
	dp[N][0] = 1;
	for(int i = N-1; i >= 0; i--) for(int j = 0; j < 10; j++) if((A[i]&dig[j]) == A[i]) {
		int d = __builtin_popcount(dig[j]-A[i]);
		for(int k = 0; k <= K-d; k++) dp[i][k+d] |= dp[i+1][k];
	}
	if(!dp[0][K]) {
		cout << "-1\n";
		return 0;
	}
	string ans;
	for(int i = 0; i < N; i++) for(int j = 9; j >= 0; j--) {
		if((A[i]&dig[j]) != A[i]) continue;
		int d = __builtin_popcount(dig[j]-A[i]);
		if(d > K) continue;
		if(!dp[i+1][K-d]) continue;
		ans += '0'+j;
		K -= d;
		break;
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing