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
	vector<string> V(N);
	for(int i = 0; i < N; i++) cin >> V[i];
	int dx[] = {-1, 0, 1}, dy[] = {-1, 0, 1};
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
		if(V[i][j] == '*') continue;
		int cnt = 0;
		for(int k = 0; k < 3; k++) for(int l = 0; l < 3; l++)
			if(i+dx[k] >= 0 && j+dy[l] >= 0 && i+dx[k] < N && j+dy[l] < M)
				if(V[i+dx[k]][j+dy[l]] == '*') cnt++;
		int cnt_exp = (V[i][j] == '.') ? 0 : (V[i][j]-'0');
		if(cnt != cnt_exp) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}

// look at my code
// my code is amazing