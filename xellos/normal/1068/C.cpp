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
	int N, M;
	cin >> N >> M;
	vector< vector< pair<int, int> > > ans(N);
	for(int i = 0; i < N; i++) ans[i] = {{i+1, i+1}};
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ans[a-1].push_back({a, N+1+i});
		ans[b-1].push_back({b, N+1+i});
	}
	for(int i = 0; i < N; i++) {
		cout << ans[i].size() << "\n";
		ALL_THE(ans[i], it) cout << it->ff << " " << it->ss << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing