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
		string S;
		cin >> N >> S;
		int r = N;
		while(r > 0 && S[r-1] == S[0]) r--;
		int ans = 0;
		for(int i = 0; i < r; i++) if(i == 0 || S[i-1] != S[i]) {
			int sz = 0;
			while(sz+i < r && S[sz+i] == S[i]) sz++;
			if(i == 0) sz += N-r;
			ans += sz/3;
		}
		if(r == 0) {
			ans = 1;
			int sz = N-1;
			ans += sz/3;
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing