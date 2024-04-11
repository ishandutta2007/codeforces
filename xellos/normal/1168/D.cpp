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
	int N, Q;
	cin >> N >> Q;
	vector< vector<int> > son(N);
	vector<int> par(N, 0), C(N, -1), dep(N, 0);
	for(int i = 1; i < N; i++) {
		string c;
		cin >> par[i] >> c;
		C[i] = (c[0] == '?') ? -1 : (c[0]-'a');
		son[--par[i]].push_back(i);
		dep[i] = dep[par[i]] + 1;
	}
	int max_dep = 0;
	for(int i = 0; i < N; i++) max_dep = max(max_dep, dep[i]);

	for(int i = 0; i < N; i++) if(max_dep != dep[i] && son[i].empty()) {
		for(int q = 0; q < Q; q++) cout << "Fou\n";
		return 0;
	}

	vector< vector<int> > son_c(N);
	vector<int> par_c(N, 0), path_id(N);
	vector< vector<int> > cnt(N, vector<int>(26, 0));
	for(int i = 1; i < N; i++) if((int)son[i].size() != 1) {
		path_id[i] = i;
		if(C[i] != -1) cnt[i][C[i]]++;
		int p = par[i];
		while(p != 0 && (int)son[p].size() == 1) {
			if(C[p] != -1) cnt[i][C[p]]++;
			path_id[p] = i;
			p = par[p];
		}
		par_c[i] = p;
		son_c[p].push_back(i);
	}

	queue<int> q_fail;
	vector<char> failed(N, 0);
	vector< vector<int> > max_cnt(N, vector<int>(26, 0));
	vector<int> sum(N, 0);
	for(int i = N-1; i >= 0; i--) if(i == 0 || (int)son[i].size() != 1) {
		for(int j = 0; j < 26; j++) {
			sum[i] += max_cnt[i][j];
			if(i > 0) max_cnt[par_c[i]][j] = max(max_cnt[par_c[i]][j], max_cnt[i][j] + cnt[i][j]);
		}
		if(sum[i] > max_dep-dep[i]) {
			failed[i] = 1;
			q_fail.push(i);
		}
	}

	for(int q = 0; q < Q; q++) {
		int v;
		string c;
		cin >> v >> c;
		v--;

		int val_new = (c[0] == '?') ? -1 : (c[0]-'a');
		int val_old = C[v];
		C[v] = val_new;
		v = path_id[v];
		if(val_old != -1) cnt[v][val_old]--;
		if(val_new != -1) cnt[v][val_new]++;

		while(v != 0) {
			int p = par_c[v];
			int other_son = ((int)son_c[p].size() < 2) ? 0 : (son_c[p][0]+son_c[p][1]-v);
			if(val_old != -1) {
				sum[p] -= max_cnt[p][val_old];
				max_cnt[p][val_old] = max_cnt[v][val_old] + cnt[v][val_old];
				if(other_son != 0) max_cnt[p][val_old] = max(max_cnt[p][val_old],
					max_cnt[other_son][val_old] + cnt[other_son][val_old]);
				sum[p] += max_cnt[p][val_old];
			}
			if(val_new != -1 && val_old != val_new) {
				sum[p] -= max_cnt[p][val_new];
				max_cnt[p][val_new] = max_cnt[v][val_new] + cnt[v][val_new];
				if(other_son != 0) max_cnt[p][val_new] = max(max_cnt[p][val_new],
					max_cnt[other_son][val_new] + cnt[other_son][val_new]);
				sum[p] += max_cnt[p][val_new];
			}
			failed[v] = true;
			q_fail.push(v);
			v = par_c[v];
		}
		failed[0] = 1;
		q_fail.push(0);

		while(!q_fail.empty()) {
			v = q_fail.front();
			if(failed[v] == 0) {
				q_fail.pop();
				continue;
			}
			if(sum[v] > max_dep-dep[v]) break;
			else {
				q_fail.pop();
				failed[v] = 0;
			}
		}

		if(!q_fail.empty()) cout << "Fou\n";
		else {
			cat F = 0;
			for(int i = 0; i < 26; i++) F += (i+1LL) * (max_dep-sum[0]+max_cnt[0][i]);
			cout << "Shi " << F << "\n";
		}
	}
	return 0;
}

// look at my code
// my code is amazing