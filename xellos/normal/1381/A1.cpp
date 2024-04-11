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
		string A, B;
		cin >> N >> A >> B;
		vector<int> ans;
		int l = 0, r = N-1, f = 0;
		for(int i = N-1; i >= 0; i--) {
			// cout << l << "." << r << endl;
			if((A[r] == B[i]) != (f&1)) {
				if(l < r) r--;
				else r++;
				continue;
			}
			if((A[l] == B[i]) != (f&1)) ans.push_back(1);
			ans.push_back(i+1);
			f++;
			if(l < r) l++;
			else l--;
			swap(l, r);
		}
		cout << ans.size();
		for(int i = 0; i < (int)ans.size(); i++) cout << " " << ans[i];
		cout << "\n";
	}
}

// look at my code
// my code is amazing