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

struct debt {
	int u, v;
	cat d;
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector<cat> D(N, 0);
	for(int i = 0; i < M; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		D[u-1] += d;
		D[v-1] -= d;
	}
	vector<debt> ans;
	for(int i = 0, j = 0; i < N; i++) while(D[i] > 0) {
		while(D[j] >= 0) j++;
		cat x = min(D[i], -D[j]);
		ans.push_back({i, j, x});
		D[i] -= x;
		D[j] += x;
	}
	cout << ans.size() << "\n";
	for(auto d : ans) cout << d.u+1 << " " << d.v+1 << " " << d.d << "\n";
}

// look at my code
// my code is amazing