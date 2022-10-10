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
	vector<int> A(N+1), D(N);
	for(int i = 0; i < N; i++) cin >> A[i+1];
	for(int i = 0; i < N; i++) D[i] = A[i+1] - A[i];
	// D[i] = X[i%K]
	vector<int> ans;
	for(int k = 1; k <= N; k++) {
		bool ok = true;
		for(int i = 0; i < N; i++) if(D[i] != D[i%k]) {
			ok = false;
			break;
		}
		if(ok) ans.push_back(k);
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < (int)ans.size(); i++) cout << ans[i] << ((i+1 == (int)ans.size()) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing