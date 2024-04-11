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
		int R, C;
		cin >> R >> C;
		vector<string> V(R);
		for(int i = 0; i < R; i++) cin >> V[i];
		bool fail = true;
		for(int i = 0; i < R; i++) for(int j = 0; j < C; j++)
			if(V[i][j] == 'A') fail = false;
		if(fail) {
			cout << "MORTAL\n";
			continue;
		}
		bool needs4 = true;
		for(int i = 0; i < R; i++) for(int j = 0; j < C; j++)
			if(i == 0 || j == 0 || i == R-1 || j == C-1)
				if(V[i][j] == 'A') needs4 = false;
		if(needs4) {
			cout << "4\n";
			continue;
		}
		bool zero = true;
		for(int i = 0; i < R; i++) for(int j = 0; j < C; j++)
			if(V[i][j] == 'P') zero = false;
		if(zero) {
			cout << "0\n";
			continue;
		}

		bool one = true;
		for(int i = 0; i < R; i++)
			if(V[i][0] == 'P') one = false;
		if(one) {
			cout << "1\n";
			continue;
		}
		one = true;
		for(int i = 0; i < C; i++)
			if(V[0][i] == 'P') one = false;
		if(one) {
			cout << "1\n";
			continue;
		}
		one = true;
		for(int i = 0; i < R; i++)
			if(V[i][C-1] == 'P') one = false;
		if(one) {
			cout << "1\n";
			continue;
		}
		one = true;
		for(int i = 0; i < C; i++)
			if(V[R-1][i] == 'P') one = false;
		if(one) {
			cout << "1\n";
			continue;
		}

		bool two = (V[0][0] == 'A' || V[R-1][C-1] == 'A' || V[R-1][0] == 'A' || V[0][C-1] == 'A');
		for(int i = 0; i < R; i++) {
			bool ok = true;
			for(int j = 0; j < C; j++) if(V[i][j] == 'P') ok = false;
			if(ok) two = true;
		}
		for(int i = 0; i < C; i++) {
			bool ok = true;
			for(int j = 0; j < R; j++) if(V[j][i] == 'P') ok = false;
			if(ok) two = true;
		}
		if(two) cout << "2\n";
		else cout << "3\n";
	}
	return 0;
}

// look at my code
// my code is amazing