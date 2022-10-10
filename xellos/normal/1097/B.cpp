#include <bits/stdc++.h>
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
	int N;
	cin >> N;
	vector<int> pos(360, 0);
	pos[0] = 1;
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vector<int> pos_nw(360, 0);
		for(int j = 0; j < 360; j++) if(pos[j]) {
			pos_nw[(a+j)%360] = 1;
			pos_nw[(a+360-j)%360] = 1;
		}
		pos = pos_nw;
	}
	if(pos[0]) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}

// look at my code
// my code is amazing