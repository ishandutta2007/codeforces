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
		int x;
		string S;
		cin >> x >> S;
		cat L = S.length(), cur = 0, mod = 1000000007;
		bool app = true;
		while(cur != x) {
			cur++;
			if(S[cur-1] >= '2' && app) S += S.substr(cur, L-cur);
			if(S[cur-1] >= '3' && app) S += S.substr(cur, L-cur);
			L = (L + 1LL * (L-cur) * (S[cur-1]-'1')) % mod;
			if(L < 0) L += mod;
			if(L >= x) app = false;
		}
		cout << L << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing