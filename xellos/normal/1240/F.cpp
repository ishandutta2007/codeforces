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

struct edge {
	int u, v, id;
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> W(N), D(N, 0);
	for(int i = 0; i < N; i++) cin >> W[i];
	vector<edge> E(M);
	for(int i = 0; i < M; i++) {
		cin >> E[i].u >> E[i].v;
		D[--E[i].u]++;
		D[--E[i].v]++;
		E[i].id = i;
	}
	vector<edge> E0 = E;
	int M0 = M;
	vector<edge> E_final;
	while(true) {
		bool stop = true;
		for(int i = 0; i < M; i++) if(min(D[E[i].u], D[E[i].v]) <= 2) {
			D[E[i].u]--;
			D[E[i].v]--;
			E_final.push_back(E[i]);
			swap(E.back(), E[i]);
			E.pop_back();
			M--;
			stop = false;
			break;
		}
		for(int i = 0; i < M; i++) if((D[E[i].u]-1)/2+(D[E[i].v]-1)/2 < K) {
			D[E[i].u]--;
			D[E[i].v]--;
			E_final.push_back(E[i]);
			swap(E.back(), E[i]);
			E.pop_back();
			M--;
			stop = false;
			break;
		}
		if(stop) break;
	}
	reverse(begin(E_final), end(E_final));
	vector< vector<int> > S_final(N, vector<int>(K, 0));
	vector<int> ans_id(M0, 0);
	int ans = 0;
	if(M > 0) {
		vector< vector<int> > seqs(10000, vector<int>(K));
		for(int i = 0; i < 10000; i++) for(int j = 0; j < K; j++) {
			seqs[i][j] = j;
			swap(seqs[i][j], seqs[i][rand()%(j+1)]);
		}
		for(int r = 0; r < 50; r++) {
			srand(r);
			for(int i = 0; i < M; i++) swap(E[rand()%(i+1)], E[i]);
			vector<char> used(M, 0);
			vector< vector<int> > S(N, vector<int>(K, 0)), S_cnt(N, vector<int>(3, 0));
			vector<int> S_min(N, 0);
			for(int i = 0; i < N; i++) S_cnt[i][0] = K;
			int cur = 0;
			vector<int> cur_id(M0, 0);
			for(int r2 = 0; r2 < (400/K); r2++) {
				auto cur_old = cur;
				auto used_old = used;
				auto cur_id_old = cur_id;
				auto S_min_old = S_min;
				auto S_old = S;
				auto S_cnt_old = S_cnt;
				for(int i = 0; i < M; i++) if(used[i] && rand()%4 == 0) {
					int s = cur_id[E[i].id]-1, u = E[i].u, v = E[i].v;
					if(S[u][s] == S_min[u] && S_cnt[u][2]) continue;
					if(S[v][s] == S_min[v] && S_cnt[v][2]) continue;
					cur_id[E[i].id] = 0;
					S_cnt[u][S[u][s]-S_min[u]]--;
					S_cnt[v][S[v][s]-S_min[v]]--;
					if(S[u][s] == S_min[u]) {
						S_cnt[u][2] = S_cnt[u][1];
						S_cnt[u][1] = S_cnt[u][0];
						S_cnt[u][0] = 0;
						S_min[u]--;
					}
					if(S[v][s] == S_min[v]) {
						S_cnt[v][2] = S_cnt[v][1];
						S_cnt[v][1] = S_cnt[v][0];
						S_cnt[v][0] = 0;
						S_min[v]--;
					}
					S[u][s]--;
					S[v][s]--;
					S_cnt[u][S[u][s]-S_min[u]]++;
					S_cnt[v][S[v][s]-S_min[v]]++;
					cur -= W[u] + W[v];
					used[i] = 0;
				}
				for(int i = 0; i < M; i++) if(!used[i]) {
					int seq_id = rand()%10000, u = E[i].u, v = E[i].v;
					int s = -1;
					for(int j = 0; j < K; j++) {
						int cur_s = seqs[seq_id][j];
						if(S[u][cur_s] == 2+S_min[u]) continue;
						if(S[v][cur_s] == 2+S_min[v]) continue;
						s = cur_s;
						break;
					}
					if(s == -1) continue;
					cur_id[E[i].id] = s+1;
					S_cnt[u][S[u][s]-S_min[u]]--;
					S_cnt[v][S[v][s]-S_min[v]]--;
					if(S_cnt[u][0] == 0) {
						S_cnt[u][0] = S_cnt[u][1];
						S_cnt[u][1] = S_cnt[u][2];
						S_cnt[u][2] = 0;
						S_min[u]++;
					}
					if(S_cnt[v][0] == 0) {
						S_cnt[v][0] = S_cnt[v][1];
						S_cnt[v][1] = S_cnt[v][2];
						S_cnt[v][2] = 0;
						S_min[v]++;
					}
					S[u][s]++;
					S[v][s]++;
					S_cnt[u][S[u][s]-S_min[u]]++;
					S_cnt[v][S[v][s]-S_min[v]]++;
					cur += W[u] + W[v];
					used[i] = 1;
				}
				if(cur < cur_old) {
					cur = cur_old;
					used = used_old;
					cur_id = cur_id_old;
					S_min = S_min_old;
					S = S_old;
					S_cnt = S_cnt_old;
				}
			}
			if(cur > ans) {
				ans = cur;
				ans_id = cur_id;
				S_final = S;
			}
		}
	}
	for(auto e : E_final) {
		int min_u = 1000000, min_v = 1000000;
		for(int i = 0; i < K; i++) min_u = min(min_u, S_final[e.u][i]);
		for(int i = 0; i < K; i++) min_v = min(min_v, S_final[e.v][i]);
		for(int i = 0; i < K; i++) if(S_final[e.u][i]+1 <= min_u+2 && S_final[e.v][i]+1 <= min_v+2) {
			S_final[e.u][i]++;
			S_final[e.v][i]++;
			ans_id[e.id] = i+1;
			ans += W[e.u] + W[e.v];
			break;
		}
	}
	cerr << ans << "\n";
	for(int i = 0; i < M0; i++) cout << ans_id[i] << "\n";
	return 0;
}

// look at my code
// my code is amazing