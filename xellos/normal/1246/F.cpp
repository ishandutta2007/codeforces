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
	string S;
	cin >> S;
	int N = S.length();
	if(N == 1) {
		cout << "0\n";
		return 0;
	}

	vector< vector<int> > right_occ(N, vector<int>(26, N));
	for(int i = 0; i < 26; i++) for(int j = N-1; j >= 0; j--) {
		if(S[j] == 'a'+i) right_occ[j][i] = j;
		else if(j < N-1) right_occ[j][i] = right_occ[j+1][i];
	}
	vector< vector<int> > left_occ(N, vector<int>(26, -1));
	for(int i = 0; i < 26; i++) for(int j = 0; j < N-1; j++) {
		if(S[j] == 'a'+i) left_occ[j][i] = j;
		else if(j > 0) left_occ[j][i] = left_occ[j-1][i];
	}
	vector< pair<int, int> > I(N);
	for(int k = 0; k < 26; k++) {
		for(int i = 0, last = 0; i < N; i++) if(S[i] == 'a'+k) {
			I[i].ff = last;
			last = i;
		}
		for(int i = N-1, last = N-1; i >= 0; i--) if(S[i] == 'a'+k) {
			I[i].ss = last;
			last = i;
		}
	}

	vector< vector<int> > RMQ_I_right(20, vector<int>(N, -1));
	vector< vector<int> > RMQ_id_right(20, vector<int>(N, -1));
	for(int i = 0; i < N; i++) {
		RMQ_I_right[0][i] = I[i].ss;
		RMQ_id_right[0][i] = i;
	}
	for(int k = 1; k < 20; k++) for(int i = 0; i <= N-(1<<k); i++) {
		RMQ_I_right[k][i] = max(RMQ_I_right[k-1][i], RMQ_I_right[k-1][i+(1<<(k-1))]);
		if(RMQ_I_right[k][i] == RMQ_I_right[k-1][i])
			RMQ_id_right[k][i] = RMQ_id_right[k-1][i];
		else RMQ_id_right[k][i] = RMQ_id_right[k-1][i+(1<<(k-1))];
	}
	vector<int> next_right(N);
	for(int i = 0; i < N; i++) {
		next_right[i] = i;
		int d = I[i].ss-i, cur = i+1;
		for(int k = 0; k < 20; k++) if((d>>k)&1) {
			if(RMQ_I_right[k][cur] >= I[next_right[i]].ss)
				next_right[i] = RMQ_id_right[k][cur];
			cur += 1<<k;
		}
	}
	vector< vector<int> > RMQ_I_left(20, vector<int>(N, N));
	vector< vector<int> > RMQ_id_left(20, vector<int>(N, N));
	for(int i = 0; i < N; i++) {
		RMQ_I_left[0][i] = I[i].ff;
		RMQ_id_left[0][i] = i;
	}
	for(int k = 1; k < 20; k++) for(int i = (1<<k)-1; i < N; i++) {
		RMQ_I_left[k][i] = min(RMQ_I_left[k-1][i], RMQ_I_left[k-1][i-(1<<(k-1))]);
		if(RMQ_I_left[k][i] == RMQ_I_left[k-1][i])
			RMQ_id_left[k][i] = RMQ_id_left[k-1][i];
		else RMQ_id_left[k][i] = RMQ_id_left[k-1][i-(1<<(k-1))];
	}
	vector<int> next_left(N);
	for(int i = 0; i < N; i++) {
		next_left[i] = i;
		int d = i-I[i].ff, cur = i-1;
		for(int k = 0; k < 20; k++) if((d>>k)&1) {
			if(RMQ_I_left[k][cur] <= I[next_left[i]].ff)
				next_left[i] = RMQ_id_left[k][cur];
			cur -= 1<<k;
		}
	}

	vector< vector<int> > RMQ_next_right(20, vector<int>(N));
	vector< vector<cat> > RMQ_sum_right(20, vector<cat>(N));
	for(int i = 0; i < N; i++) {
		RMQ_next_right[0][i] = next_right[i];
		RMQ_sum_right[0][i] = I[next_right[i]].ss - I[i].ss;
	}
	for(int k = 1; k < 20; k++) for(int i = 0; i < N; i++) {
		RMQ_next_right[k][i] = RMQ_next_right[k-1][RMQ_next_right[k-1][i]];
		RMQ_sum_right[k][i] = RMQ_sum_right[k-1][i] + RMQ_sum_right[k-1][RMQ_next_right[k-1][i]]
			+ (1LL<<(k-1)) * (I[RMQ_next_right[k][i]].ss - I[RMQ_next_right[k-1][i]].ss);
	}
	vector< vector<int> > RMQ_next_left(20, vector<int>(N));
	vector< vector<cat> > RMQ_sum_left(20, vector<cat>(N));
	for(int i = 0; i < N; i++) {
		RMQ_next_left[0][i] = next_left[i];
		RMQ_sum_left[0][i] = I[i].ff - I[next_left[i]].ff;
	}
	for(int k = 1; k < 20; k++) for(int i = 0; i < N; i++) {
		RMQ_next_left[k][i] = RMQ_next_left[k-1][RMQ_next_left[k-1][i]];
		RMQ_sum_left[k][i] = RMQ_sum_left[k-1][i] + RMQ_sum_left[k-1][RMQ_next_left[k-1][i]]
			+ (1LL<<(k-1)) * (I[RMQ_next_left[k-1][i]].ff - I[RMQ_next_left[k][i]].ff);
	}

	cat ans = 0;
	for(int i = 0; i < N; i++) {
		cat sum = I[i].ss-I[i].ff, dist = 1;
		int left_cur = i, right_cur = i;
		while(I[left_cur].ff > 0 || I[right_cur].ss < N-1) {
			int L = -1, R = N;
			for(int j = 0; j < 26; j++) if(right_occ[left_cur][j] > right_cur) {
				L = max(L, left_occ[i][j]);
				R = min(R, right_occ[i][j]);
			}
			L++, R--;

			for(int k = 19; k >= 0; k--) {
				int right_nxt = RMQ_next_right[k][right_cur];
				int left_nxt = RMQ_next_left[k][left_cur];
				if(I[left_nxt].ff < L || I[right_nxt].ss > R) continue;
				sum += dist * (I[right_nxt].ss-I[right_cur].ss) + RMQ_sum_right[k][right_cur];
				sum += dist * (I[left_cur].ff-I[left_nxt].ff) + RMQ_sum_left[k][left_cur];
				left_cur = left_nxt, right_cur = right_nxt;
				dist += 1<<k;
				if(I[left_cur].ff == 0 && I[right_cur].ss == N-1) break;
			}

			pair<int, int> I_cur = {I[left_cur].ff, I[right_cur].ss};
			pair<int, int> I_nxt = I_cur;
			int left_nxt = left_cur, right_nxt = right_cur;
			for(int k = 19, cur = I_cur.ff; k >= 0; k--) {
				if(cur+(1<<k) > I_cur.ss+1) continue;
				if(RMQ_I_right[k][cur] >= I_nxt.ss) {
					I_nxt.ss = RMQ_I_right[k][cur];
					right_nxt = RMQ_id_right[k][cur];
				}
				cur += 1<<k;
			}
			for(int k = 19, cur = I_cur.ss; k >= 0; k--) {
				if(cur-(1<<k) < I_cur.ff-1) continue;
				if(RMQ_I_left[k][cur] <= I_nxt.ff) {
					I_nxt.ff = RMQ_I_left[k][cur];
					left_nxt = RMQ_id_left[k][cur];
				}
				cur -= 1<<k;
			}
			dist++;
			sum += dist * (I_nxt.ss-I_cur.ss+I_cur.ff-I_nxt.ff);
			left_cur = left_nxt, right_cur = right_nxt;
			I_cur = I_nxt;
		}
		ans += sum;
		// cout << sum << " ";
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing