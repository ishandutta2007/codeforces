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
	vector<int> D(N);
	cat psum = 0;
	for(int i = 0; i < N; i++) {
		cin >> D[i];
		psum ^= D[i]&1;
	}
	sort(begin(D), end(D));
	reverse(begin(D), end(D));
	D.insert(begin(D), N+1);
	N++; // N vertices in total, D[1..N-1] on input

	vector<cat> S(N, 0);
	for(int i = 1; i < N; i++) S[i] = S[i-1] + D[i];

	vector<int> cnt_gt_add(N, 0);
	int cnt_gt = 0;
	vector<cat> R(N+1, 0);
	for(int i = N-1; i > 0; i--) {
		R[i] = R[i+1] - cnt_gt + min(i, D[i]);
		if(D[i] > i) cnt_gt++;
		else cnt_gt_add[D[i]]++;
		cnt_gt += cnt_gt_add[i];
	}

	cnt_gt_add = vector<int>(N, 0);
	cnt_gt = 0;
	vector<cat> Rx(N+1, 0);
	for(int i = N-1; i > 0; i--) {
		Rx[i] = Rx[i+1] - cnt_gt + min(i-1, D[i]);
		if(D[i] >= i) cnt_gt++;
		else cnt_gt_add[D[i]]++;
		cnt_gt += cnt_gt_add[i-1];
	}

	vector<cat> lb(N+1, 0), ub(N+2, N-1);
	// ub[k] = min(N >= j >= k) (j*(j-1)+R[j]-S[j-1])
	// lb[k] = max(1 <= j < k)  (S[j]-j*(j-1)-Rx[j+1])
	for(int k = 2; k <= N; k++)
		lb[k] = max(lb[k-1], S[k-1]-1LL*(k-1)*(k-2)-Rx[k]);
	for(int k = N; k >= 1; k--)
		ub[k] = min(ub[k+1], 1LL*k*(k-1)+R[k]-S[k-1]);

	vector<int> ans;
	D.push_back(0);
	for(int k = 1; k <= N; k++) {
		// D[k-1] > d >= D[k]
		if(1LL*(k-1)*(k-1)+Rx[k]-S[k-1] < 0) break;
		cat l = max(lb[k], (cat)D[k]), r = min(D[k-1]-1LL, ub[k]);
		if((l+psum) % 2) l++;
		if((r+psum) % 2) r--;
		if(l > r) continue;
		for(int D = r; D >= l; D -= 2) ans.push_back(D);
	}
	if(ans.empty()) {
		cout << "-1\n";
		return 0;
	}
	reverse(begin(ans), end(ans));
	for(int i = 0; i < (int)ans.size(); i++) cout << ans[i] << ((i == (int)ans.size()-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing