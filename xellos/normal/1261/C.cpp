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
#define OVER9000 1234567890123456789LL
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

struct query {
	int K, id, q_id;

	bool operator<(const query & Q) const {
		return K < Q.K;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector<string> S(N);
	for(int i = 0; i < N; i++) cin >> S[i];
	int t_max = 2000, t_min = 0;
	vector< vector<int> > init_sum(N+1, vector<int>(M+1, 0));
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
		init_sum[i+1][j+1] = init_sum[i][j+1] + init_sum[i+1][j] - init_sum[i][j] + (S[i][j] == 'X');
	vector< vector<int> > fire(N+1, vector<int>(M+1));
	auto ans_opt = fire;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) ans_opt[i][j] = (S[i][j] == 'X');
	while(t_max-t_min > 1) {
		int t = (t_min + t_max) / 2;
		bool ok = true;
		vector< vector<int> > ans_cur(N, vector<int>(M, 0));
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
			fire[i][j] = 0;
			if(S[i][j] == '.') continue;
			if(i-t < 0 || j-t < 0 || i+t >= N || j+t >= M) continue;
			if(init_sum[i+t+1][j+t+1] + init_sum[i-t][j-t] - init_sum[i+t+1][j-t] - init_sum[i-t][j+t+1] == (2*t+1)*(2*t+1)) {
				ans_cur[i][j] = 1;
				fire[i-t][j-t] = 2*t+1;
			}
		}
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) if(fire[i][j])
			fire[i][j+1] = max(fire[i][j+1], fire[i][j]-1);
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) if(fire[i][j])
			fire[i][j] = 2*t+1;
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) if(fire[i][j])
			fire[i+1][j] = max(fire[i+1][j], fire[i][j]-1);
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
			if(fire[i][j] && S[i][j] == '.') ok = false;
			if(fire[i][j] == 0 && S[i][j] == 'X') ok = false;
		}
		if(!ok) t_max = t;
		else t_min = t, ans_opt = ans_cur;
	}
	cout << t_min << "\n";
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) S[i][j] = ans_opt[i][j] ? 'X' : '.';
	for(int i = 0; i < N; i++) cout << S[i] << "\n";
	return 0;
}

// look at my code
// my code is amazing