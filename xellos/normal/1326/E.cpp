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
#include <cassert>
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

void update(int id, int K, auto & op, int & min_val, int & sum, int & max_fail) {
	sum = 0;
	min_val = 0;
	int min_ok = 0;
	for(int i = id*K; i < id*K+K; i++) {
		sum += op[i], min_val += op[i];
		if(min_val == -1) min_val = 0;
		if(min_ok + sum < 0) min_ok++;
	}
	max_fail = min_ok-1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> pos(N);
	for(int i = 0, p; i < N; i++) {
		cin >> p;
		pos[--p] = i;
	}
	int K = 500;
	vector<int> op(2*N+K+10, 0);
	vector<int> max_fail(2*N/K+10, -1), min_val(2*N/K+10, 0), sum(2*N/K+10, 0);
	int ans = N;
	cout << N;
	for(int q = 0; q < N-1; q++) {
		int a;
		cin >> a;
		a--;
		op[2*a+1] = -1;
		int id = (2*a+1)/K;
		update(id, K, op, min_val[id], sum[id], max_fail[id]);
		while(true) {
			// check ans
			int cur = 0;
			for(int i = 0; i < 2*pos[ans-1]/K; i++) {
				if(cur > max_fail[i]) cur += sum[i];
				else cur = min_val[i];
			}
			for(int i = 2*pos[ans-1]/K*K; i < 2*pos[ans-1]; i++) {
				cur += op[i];
				if(cur == -1) cur = 0;
			}
			bool ok = true;
			for(int i = 2*pos[ans-1]+1; i < 2*pos[ans-1]/K*K+K; i++) {
				cur += op[i];
				if(cur == -1) {
					ok = false;
					break;
				}
			}
			if(ok) for(int i = 2*pos[ans-1]/K+1; i <= 2*N/K; i++) {
				if(max_fail[i] >= cur) {
					ok = false;
					break;
				}
				cur += sum[i];
			}
			if(ok) break;
			ans--;
			op[2*pos[ans]] = 1;
			id = (2*pos[ans])/K;
			update(id, K, op, min_val[id], sum[id], max_fail[id]);
		}
		cout << " " << ans;
	}
	cout << "\n";
	return 0;
}

// look at my code
// my code is amazing