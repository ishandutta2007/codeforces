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
	cat K;
	cin >> K;
	int ans = 200000;
	string ans_str;
	for(int k = 1; k <= 100; k++) for(int n = 1; n <= 10; n++) {
		cat cnt = 1;
		for(int i = 0; i < n; i++) if(cnt < K) cnt *= k;
		for(int i = 0; i < 10-n; i++) if(cnt < K) cnt *= k+1;
		if(cnt >= K && n*k+(10-n)*(k+1) < ans) {
			ans = n*k+(10-n)*(k+1);
			string s = "codeforces";
			ans_str = "";
			for(int i = 0; i < n; i++) for(int j = 0; j < k; j++) ans_str += s[i];
			for(int i = n; i < 10; i++) for(int j = 0; j <= k; j++) ans_str += s[i];
		}
	}
	cout << ans_str << "\n";
}

// look at my code
// my code is amazing