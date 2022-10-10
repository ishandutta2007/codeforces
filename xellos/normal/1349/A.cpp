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
	int N, MX = 200000;
	cin >> N;
	vector<int> occ(MX+1, 0);
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		occ[a]++;
	}
	vector<char> P(MX+1, 1);
	cat ans = 1;
	for(int i = 2; i <= MX; i++) if(P[i]) {
		for(int j = 2*i; j <= MX; j += i) P[j] = 0;
		vector<int> exp_occ(20, 0);
		int e = 1;
		cat p = i;
		while(e < 20) {
			for(int j = p; j <= MX; j += p) exp_occ[e] += occ[j];
			e++;
			p *= i;
			if(p > MX) break;
		}
		exp_occ[0] = N;
		for(int j = 1; j < 20; j++) exp_occ[j-1] -= exp_occ[j];
		e = 0;
		while(exp_occ[e] == 0) e++;
		if(exp_occ[e] == 1) {
			e++;
			while(exp_occ[e] == 0) e++;
		}
		for(int j = 0; j < e; j++) ans *= i;
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing