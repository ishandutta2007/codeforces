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
	vector<cat> V(N);
	for(int i = 0; i < N; i++) cin >> V[i];
	cat ans[3] = {0, 0, 0};
	for(int i = 1; i <= M; i++) {
		cat cnt = 0;
		for(int j = 0; j < N; j++) cnt += (V[j]/i) % 2;
		ans[2-cnt%2]++;
	}
	for(int s = 2; s <= 2*M; s++) {
		vector<int> A(N);
		for(int i = 0; i < N; i++) A[i] = V[i] % s;
		int max_smaller = 0;
		for(int i = 0; i < N; i++) max_smaller = max(max_smaller, min(A[i], s-1-A[i]));
		max_smaller = min(max_smaller, (s-1)/2);
		if(max_smaller >= max(1, s-M))
			ans[0] += max_smaller - max(1, s-M) + 1;
		int min_next = max(max(1, s-M), max_smaller+1);
		if(min_next > (s-1)/2) continue;
		int max_A[2] = {0, 0};
		for(int i = 0; i < N; i++) max_A[0] = max(max_A[0], A[i]);
		for(int i = 0; i < N; i++) if(max_A[0] == A[i]) {
			for(int j = 0; j < N; j++) if(j != i) max_A[1] = max(max_A[1], A[j]);
			break;
		}
		max_A[0] /= 2, max_A[1] /= 2;
		int cnt = 0;
		for(int i = 0; i < N; i++) if(A[i] >= (s+1)/2) cnt++;
		if(max_A[cnt%2] >= min_next)
			ans[0] += max_A[cnt%2]-min_next+1;
		min_next = max(min_next, max_A[cnt%2]+1);
		ans[2-cnt%2] += 2 * ((s-1)/2 - min_next + 1);
	}
	cout << ans[0] << " " << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
	return 0;
}

// look at my code
// my code is amazing