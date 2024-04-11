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
	vector<string> S(N);
	vector<int> sum(N, 0), mi(N, 0);
	for(int i = 0; i < N; i++) {
		cin >> S[i];
		for(int j = 0; j < (int)S[i].length(); j++) {
			sum[i] += ((S[i][j] == '(') ? 1 : -1);
			mi[i] = min(mi[i], sum[i]);
		}
	}
	vector< vector<int> > by_val(600000);
	for(int i = 0; i < N; i++) by_val[abs(sum[i])].push_back(i);
	int ans = 0;
	for(int i = 1; i < 600000; i++) {
		int cnt_pos = 0, cnt_neg = 0;
		ALL_THE(by_val[i], it) {
			if(sum[*it] < 0 && mi[*it] >= -i) cnt_neg++;
			if(sum[*it] > 0 && mi[*it] >= 0) cnt_pos++;
		}
		ans += min(cnt_pos, cnt_neg);
	}
	int cnt0 = 0;
	ALL_THE(by_val[0], it) if(mi[*it] >= 0) cnt0++;
	ans += cnt0/2;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing