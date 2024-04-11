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
	vector<int> max_cnt(N+1, 0);
	vector<int> cur_cnt(2*N+10, 0);
	for(int i = 0, c = 0; i < N; i++) {
		int a = i+1;
		c += cur_cnt[a];
		for(int j = 0; j < i; j++) cur_cnt[a+j+1]++;
		max_cnt[i+1] = c;
	}
	if(M > max_cnt[N]) {
		cout << "-1\n";
		return 0;
	}
	int D = 0;
	if(M == 0) {
		D = N;
		N = 0;
	}
	else {
		int n = N-1;
		while(max_cnt[n] >= M) n--, N--, D++;
	}
	vector<int> ans(N), cnt(2*N+10, 0);
	for(int i = 0; i < N; i++) ans[i] = i+1;
	for(int i = 0; i < N-1; i++) {
		M -= cnt[ans[i]];
		for(int j = 0; j < i; j++) cnt[ans[i]+ans[j]]++;
	}
	if(N) while(cnt[ans[N-1]] != M) ans[N-1]++;
	vector<char> used(1000000);
	for(int i = 0; i < N; i++) for(int j = 0; j < i; j++) used[ans[i]+ans[j]] = 1;
	for(int i = 0, mex = (N == 0) ? 1 : (ans[N-1]+1); i < D; i++) {
		while(used[mex]) mex++;
		if(!ans.empty() && ans.back()+mex >= used.size()) used.resize(ans.back()+mex+1000000, 0);
		for(int j = 0; j < (int)ans.size(); j++) used[ans[j]+mex] = 1;
		ans.push_back(mex);
		mex++;
	}
	for(int i = 0; i < N+D; i++) cout << ans[i] << "\n";
	return 0;
}

// look at my code
// my code is amazing