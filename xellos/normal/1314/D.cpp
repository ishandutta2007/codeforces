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

int get_val(int a, int b, int c, int d, int e, auto & mid) {
	int ret = 0, ok = 0;
	for(auto [v, id] : mid[a][b]) if(id != c && id != d && id != e) {
		ret += v;
		ok++;
		break;
	}
	for(auto [v, id] : mid[b][c]) if(id != d && id != e && id != a) {
		ret += v;
		ok++;
		break;
	}
	for(auto [v, id] : mid[c][d]) if(id != e && id != a && id != b) {
		ret += v;
		ok++;
		break;
	}
	for(auto [v, id] : mid[d][e]) if(id != a && id != b && id != c) {
		ret += v;
		ok++;
		break;
	}
	for(auto [v, id] : mid[e][a]) if(id != b && id != c && id != d) {
		ret += v;
		ok++;
		break;
	}
	return (ok == 5) ? ret : 1e9;
}

int get_val(int a, int b, int c, int d, auto & mid) {
	int ret = 0, ok = 0;
	for(auto [v, id] : mid[a][b]) if(id != c && id != d) {
		ret += v;
		ok++;
		break;
	}
	for(auto [v, id] : mid[b][c]) if(id != d && id != a) {
		ret += v;
		ok++;
		break;
	}
	for(auto [v, id] : mid[c][d]) if(id != a && id != b) {
		ret += v;
		ok++;
		break;
	}
	for(auto [v, id] : mid[d][a]) if(id != b && id != c) {
		ret += v;
		ok++;
		break;
	}
	return (ok == 4) ? ret : 1e9;
}

int get_val(int a, int b, int c, auto & mid) {
	int ret = 0, ok = 0;
	for(auto [v, id] : mid[a][b]) if(id != c) {
		ret += v;
		ok++;
		break;
	}
	for(auto [v, id] : mid[b][c]) if(id != a) {
		ret += v;
		ok++;
		break;
	}
	for(auto [v, id] : mid[c][a]) if(id != b) {
		ret += v;
		ok++;
		break;
	}
	return (ok == 3) ? ret : 1e9;
}

int get_val(int a, int b, auto & mid) {
	int ret = 0, ok = 0;
	for(auto [v, id] : mid[a][b]) {
		ret += v;
		ok++;
		break;
	}
	for(auto [v, id] : mid[b][a]) {
		ret += v;
		ok++;
		break;
	}
	return (ok == 2) ? ret : 1e9;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, K;
	cin >> N >> K;
	vector< vector<int> > C(N, vector<int>(N));
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		cin >> C[i][j];
	vector< vector< vector< pair<int, int> > > > mid(N, vector< vector< pair<int, int> > >(N));
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
		for(int k = 0; k < N; k++) if(k != i && k != j)
			mid[i][j].push_back({C[i][k]+C[k][j], k});
		sort(begin(mid[i][j]), end(mid[i][j]));
		if((int)mid[i][j].size() > K/2) mid[i][j].resize(K/2+1);
	}
	int ans = 1e9;
	if(K == 10)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				for(int k = 0; k < N; k++)
					for(int l = 0; l < N; l++)
							ans = min(ans, get_val(i, j, k, l, 0, mid));
	if(K == 8)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				for(int k = 0; k < N; k++)
						ans = min(ans, get_val(i, j, k, 0, mid));
	if(K == 6)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
					ans = min(ans, get_val(i, j, 0, mid));
	if(K == 4)
		for(int i = 0; i < N; i++)
				ans = min(ans, get_val(i, 0, mid));
	if(K == 2) ans = mid[0][0][0].ff;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing