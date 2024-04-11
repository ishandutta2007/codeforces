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
	int N;
	cin >> N;
	int cnt = 10000*4+(N%2)*3+(N/2)*4;
	cout << cnt << "\n";
	for(int i = 0; i <= 10000; i++) cout << i << " 0\n";
	for(int i = 0; i <= 10000; i++) cout << i << " 10000\n";
	for(int i = 1; i < 10000; i++) cout << "0 " << i << "\n";
	for(int i = 1; i < 10000; i++) cout << "10000 " << i << "\n";
	if(N%2) {
		cout << "0 -1\n";
		cout << "-1 -1\n";
		cout << "-1 0\n";
		N--;
	}
	int cur = 3;
	while(N) {
		cout << cur << " -1\n";
		cout << cur+1 << " -1\n";
		cout << cur << " 1\n";
		cout << cur+1 << " 1\n";
		cur += 4;
		N -= 2;
	}
}

// look at my code
// my code is amazing