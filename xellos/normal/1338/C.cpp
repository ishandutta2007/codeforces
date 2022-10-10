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
		cat N;
		cin >> N;
		N--;
		for(int b = 0; b < 60; b += 2) {
			cat n = 3LL<<b;
			if(n <= N) {
				N -= n;
				continue;
			}
			cat start = (1LL<<b);
			if(N%3 == 0) {
				cout << start+(N/3) << "\n";
				break;
			}
			cat ans;
			if(N%3 == 1) {
				ans = 2*start;
				N /= 3;
				for(int k = b-2; k >= 0; k -= 2) {
					cat v = (N>>k)&3;
					static cat u[4] = {0, 2, 3, 1};
					ans += u[v]<<k;
				}
			}
			else {
				ans = 3*start;
				N /= 3;
				for(int k = b-2; k >= 0; k -= 2) {
					cat v = (N>>k)&3;
					static cat u[4] = {0, 3, 1, 2};
					ans += u[v]<<k;
				}
			}
			cout << ans << "\n";
			break;
		}
	}
	return 0;
}

// look at my code
// my code is amazing