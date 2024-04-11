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

struct RMQP {
	vector<int> max_val[2][19], min_val[2][19];

	RMQP(vector<int> A) {
		int N = A.size();
		for(int p = 0; p < 2; p++) for(int k = 0; k < 19; k++) {
			max_val[p][k].resize(N/2+10, 0);
			min_val[p][k].resize(N/2+10, OVER9000);
		}
		for(int i = 0; i < N; i++) max_val[i&1][0][i/2] = min_val[i&1][0][i/2] = A[i];
		for(int p = 0; p < 2; p++) for(int k = 0; k < 18; k++)
			for(int i = 0; i <= N/2+5-(2<<k); i++) {
				max_val[p][k+1][i] = max(max_val[p][k][i], max_val[p][k][i+(1<<k)]);
				min_val[p][k+1][i] = min(min_val[p][k][i], min_val[p][k][i+(1<<k)]);
			}
	}

	int get_max(int l, int r) {
		int parity = l%2; // == r%2
		l /= 2;
		r /= 2;
		int val = 0, d = r-l+1;
		for(int k = 0; d; k++, d /= 2) if(d&1) {
			val = max(val, max_val[parity][k][l]);
			l += 1<<k;
		}
		return val;
	}

	int get_min(int l, int r) {
		int parity = l%2; // == r%2
		l /= 2;
		r /= 2;
		int val = OVER9000, d = r-l+1;
		for(int k = 0; d; k++, d /= 2) if(d&1) {
			val = min(val, min_val[parity][k][l]);
			l += 1<<k;
		}
		return val;
	}
};

int calc(vector<int> & A, vector<int> & B, vector<int> & step_B, RMQP & Q, int id, int step) {
	if(step >= step_B[id]) {
		if(!B[id]) {
			int left = calc(A, B, step_B, Q, id-1, step_B[id]-1);
			int right = calc(A, B, step_B, Q, id+1, step_B[id]-1);
			int mid = calc(A, B, step_B, Q, id, step_B[id]-1);
			if(mid > left && mid > right) B[id] = max(left, right);
			else if(mid < left && mid < right) B[id] = min(left, right);
			else B[id] = mid;
		}
		return B[id];
	}
	if(step == 0) return A[id];
	int min_this = Q.get_min(id-step, id+step), max_this = Q.get_max(id-step, id+step);
	int max_other = Q.get_max(id-step+1, id+step-1);
	if(min_this >= max_other) return min_this;
	else return max_this;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];

	RMQP Q(A);
	
	vector<int> final_step(N, 0);
	for(int i = 1; i < N-1; i++) {
		final_step[i] = max(1, final_step[i-1]-1);
		while(true) {
			if(i-final_step[i] < 0 || i+final_step[i] >= N) break;
			int min_this = Q.get_min(i-final_step[i], i+final_step[i]);
			int max_this = Q.get_max(i-final_step[i], i+final_step[i]);
			int min_other = Q.get_min(i-final_step[i]+1, i+final_step[i]-1);
			int max_other = Q.get_max(i-final_step[i]+1, i+final_step[i]-1);
			if(min_this < max_other && max_this > min_other) break;
			final_step[i]++;
		}
	}

	vector<int> final(N, 0);
	final[0] = A[0];
	final[N-1] = A[N-1];
	for(int i = 0; i < N; i++) calc(A, final, final_step, Q, i, final_step[i]);

	int min_final_step = 0;
	for(int i = 0; i < N; i++) {
		int cur = calc(A, final, final_step, Q, i, min_final_step);
		while(true) {
			int nxt = calc(A, final, final_step, Q, i, min_final_step+1);
			if(nxt == cur) break;
			cur = nxt;
			min_final_step++;
		}
	}

	cout << min_final_step << "\n";
	for(int i = 0; i < N; i++) cout << final[i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing