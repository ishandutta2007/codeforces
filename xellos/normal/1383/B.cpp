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
		int N, X = 0;
		cin >> N;
		vector<int> A(N);
		for(int i = 0; i < N; i++) {
			cin >> A[i];
			X ^= A[i];
		}
		if(X == 0) {
			cout << "DRAW\n";
			continue;
		}
		int b = 0;
		while(X > 1) X /= 2, b++;
		int cnt[2] = {0, 0};
		for(int i = 0; i < N; i++) {
			if((A[i]>>b)&1) cnt[1]++;
			else cnt[0]++;
		}
		if(cnt[1]%4 == 1) cout << "WIN\n";
		else if(cnt[0]%2 == 0) cout << "LOSE\n";
		else cout << "WIN\n";
	}
}

// look at my code
// my code is amazing