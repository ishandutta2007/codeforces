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

vector< vector<int> > seqs;
vector<int> cur_seq;

void generate_step3_res(int N, int cur_B = 1, int cur_sum = 0, int cur_sum_B = 0) {
	// B_1 >= B_2 >= ... >= B_L > 0
	// L (1+...+B_1) + (L-1) (B_1+1+...+B_2) + ... <= N
	seqs.push_back(cur_seq);
	// L++
	cur_sum += cur_sum_B * (cur_sum_B+1) / 2;
	if(cur_sum > N) return;
	// add element
	cur_sum += cur_sum_B * (cur_B-1) + cur_B * (cur_B-1) / 2;
	cur_sum_B += cur_B-1;
	for(int b = cur_B; ; b++) {
		cur_sum += ++cur_sum_B;
		if(cur_sum > N) break;
		cur_seq.push_back(b);
		generate_step3_res(N, b, cur_sum, cur_sum_B);
		cur_seq.pop_back();
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, K;
	cin >> N >> K;
	K--;
	int mod = 998244353;
	if(K == 0) {
		// partitions of N
		vector<int> dp(N+1, 0);
		dp[0] = 1;
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j <= N-i; j++) {
				dp[j+i] += dp[j];
				if(dp[j+i] >= mod) dp[j+i] -= mod;
			}
		}
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			ans += dp[i];
			if(ans >= mod) ans -= mod;
		}
		cout << ans << "\n";
		return 0;
	}
	if(K == 1) {
		// A_(1..M): A_i >= A_(i+1), sum i A_i <= N
		vector< vector<int> > dp(N+1, vector<int>(N+1, 0));
		for(int i = 0; i <= N; i++) dp[i][i] = 1;
		for(int i = 2; i <= N; i++) {
			for(int s = N; s >= 0; s--) {
				for(int j = (int)dp[s].size()-1; j > 0; j--) {
					dp[s][j-1] += dp[s][j];
					if(dp[s][j-1] >= mod) dp[s][j-1] -= mod;
				}
				for(int j = 1; j <= (N-s)/i; j++) {
					dp[s+j*i][j] += dp[s][j];
					if(dp[s+j*i][j] >= mod) dp[s+j*i][j] -= mod;
				}
				dp[s].resize(1);
				dp[s].resize(N/i+1);
			}
		}
		int ans = 0;
		for(int s = 1; s <= N; s++) for(auto x : dp[s]) {
			ans += x;
			if(ans >= mod) ans -= mod;
		}
		cout << ans << "\n";
		return 0;
	}
	K -= 2;
	// B_1 <= B_2 <= ... <= B_L > 0
	// L (1+...+B_1) + (L-1) (B_1+1+...+B_2) + ... <= N
	generate_step3_res(N);
	while(K) {
		K--;
		vector< vector<int> > seqs_nw;
		for(auto seq : seqs) {
			vector<int> seq_nw;
			int L = seq.size();
			for(int i = 0; i < L; i++) if(!i || seq[i] != seq[i-1]) {
				int cnt = 0;
				while(i+cnt < L && seq[i+cnt] == seq[i]) cnt++;
				seq_nw.push_back(cnt);
			}
			sort(begin(seq_nw), end(seq_nw));
			reverse(begin(seq_nw), end(seq_nw));
			seqs_nw.push_back(seq_nw);
		}
		seqs = seqs_nw;
		sort(begin(seqs), end(seqs));
		auto it = unique(begin(seqs), end(seqs));
		seqs.resize(it-begin(seqs));
	}
	cout << seqs.size()-1 << "\n";
	return 0;
}

// look at my code
// my code is amazing