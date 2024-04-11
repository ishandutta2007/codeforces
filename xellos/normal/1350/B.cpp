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
		int N;
		cin >> N;
		vector<int> S(N+1);
		for(int i = 0; i < N; i++) cin >> S[i+1];
		vector<int> cnt(N+1, 1);
		for(int i = N; i > 0; i--)
			for(int j = 2*i; j <= N; j += i)
				if(S[j] > S[i] && cnt[j]+1 > cnt[i])
					cnt[i] = cnt[j]+1;
		int ans = 0;
		for(int i = 1; i <= N; i++) ans = max(ans, cnt[i]);
		cout << ans << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing