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
#include <cstring>
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
	vector< vector<char> > G(N, vector<char>(N));
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < N; j++) G[i][j] = s[j]-'0';
	}

	vector<int> mask_id(1<<N, 0);
	vector< vector<int> > masks(N+1);
	for(int i = 0; i < (1<<N); i++) {
		mask_id[i] = masks[__builtin_popcount(i)].size();
		masks[__builtin_popcount(i)].push_back(i);
	}
	map< vector<int>, int> seq_id;
	seq_id[{}] = 0;
	int S = 1;
	vector<cat> cnt_sf[1500];
	cnt_sf[0] = vector<cat>(N, 0);
	vector<cat> cnt_s[1500];
	cnt_s[0] = {1};
	vector< vector< vector<int> > > seqs(N+1);
	seqs[0].push_back({});
	for(int i = 0; i < N; i++) for(auto seq : seqs[i]) {
		int id = seq_id[seq];
		int M = masks[i].size();
		// increment last element
		if(!seq.empty()) {
			seq.back()++;
			seqs[i+1].push_back(seq);
			seq_id[seq] = S;
			cnt_sf[S].resize(masks[i+1].size()*N, 0);
			cnt_s[S].resize(masks[i+1].size(), 0);
			for(int j = 0; j < M; j++)
				for(int k = 0; k < N; k++) if(!((masks[i][j]>>k)&1)) {
					int m = mask_id[masks[i][j]+(1<<k)];
					cat sum = 0;
					for(int l = 0; l < N; l++) sum += cnt_sf[id][j*N+l] * G[k][l];
					cnt_sf[S][m*N+k] += sum;
					cnt_s[S][m] += sum;
				}
			seq.back()--;
			S++;
		}
		// add new element
		if(!i || seq.back()) if((int)seq.size() <= 1 || seq.back() >= seq[seq.size()-2]) {
			seq.push_back(0);
			seqs[i+1].push_back(seq);
			seq_id[seq] = S;
			cnt_sf[S].resize(masks[i+1].size()*N, 0);
			cnt_s[S].resize(masks[i+1].size(), 0);
			for(int j = 0; j < M; j++)
				for(int k = 0; k < N; k++) if(!((masks[i][j]>>k)&1)) {
					int m = mask_id[masks[i][j]+(1<<k)];
					cat d = cnt_s[id][j];
					cnt_sf[S][m*N+k] += d;
					cnt_s[S][m] += d;
				}
			seq.pop_back();
			S++;
		}
		cnt_sf[id] = vector<cat>();
	}
	vector<cat> cnt(S, 0);
	for(int i = 0; i < S; i++) for(auto x : cnt_s[i]) cnt[i] += x;

	vector<cat> cnt_1(1<<(N-1), 0);
	for(int i = 0; i < (1<<(N-1)); i++) {
		vector<int> seq;
		for(int j = 0, l = 0; j < N; j++) {
			if((i>>j)&1) l++;
			else {
				if(l) seq.push_back(l);
				l = 0;
			}
		}
		sort(begin(seq), end(seq));
		int sum = 0;
		for(auto x : seq) sum += x+1;
		cnt_1[i] = cnt[seq_id[seq]];
		for(int j = N-sum; j > 0; j--) cnt_1[i] *= j;
	}

	vector< vector<cat> > cnt_dp(N, vector<cat>(1<<(N-1), 0));
	cnt_dp[0] = cnt_1;
	for(int k = 0; k < N-1; k++) for(int i = 0; i < (1<<(N-1)); i++) {
		if((i>>k)&1) cnt_dp[k+1][i] = cnt_dp[k][i];
		else cnt_dp[k+1][i] = cnt_dp[k][i] - cnt_dp[k][i+(1<<k)];
	}

	for(int i = 0; i < (1<<(N-1)); i++) {
		if(i) cout << " ";
		cout << cnt_dp[N-1][i];
	}
	cout << "\n";
	return 0;
}

// look at my code
// my code is amazing