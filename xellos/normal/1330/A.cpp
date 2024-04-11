// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <random>
#include <chrono>
#include <cstring>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		char occ[1000];
		memset(occ, 0, 1000);
		int N, X;
		cin >> N >> X;
		for(int i = 0, a; i < N; i++) {
			cin >> a;
			occ[a] = 1;
		}
		for(int i = 1; i < 500; i++) if(!occ[i] && X) occ[i] = 1, X--;
		for(int i = 1; i < 500; i++) if(!occ[i]) {
			cout << i-1 << "\n";
			break;
		}
	}
	return 0;
}

// look at my code
// my code is amazing