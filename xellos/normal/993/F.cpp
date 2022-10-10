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
	int N[3];
	cin >> N[0] >> N[1] >> N[2];
	string tp[2][100];
	int inp[2][100][2];
	for(int k = 0; k < 2; k++) for(int i = 0; i < N[k+1]; i++) {
		string inp_s;
		cin >> tp[k][i] >> inp_s;
		int a = 0;
		for(int j = 0; j < N[k]; j++) if(inp_s[j] == 'x') inp[k][i][a++] = j;
	}
	bool del[100];
	memset(del, 0, sizeof(del));
	vector<int> res[2];
	bool has_ok[2] = {false, false};
	vector< vector<int> > G[2];
	G[0] = G[1] = vector< vector<int> >(2*N[0], vector<int>(2*N[0], 0));
	for(int i = 0; i < N[2]; i++) {
		int tp_inp[2];
		for(int j = 0; j < 2; j++) tp_inp[j] = (tp[0][inp[1][i][j]] == "or" || tp[0][inp[1][i][j]] == "and");
		vector<int> inputs(N[0], 0);
		for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++)
			inputs[inp[0][inp[1][i][j]][k]]++;
		int num_inputs = 0;
		for(int j = 0; j < N[0]; j++) if(inputs[j]) num_inputs++;
		if(tp_inp[0] == tp_inp[1] || num_inputs == 4) {
			del[i] = true;
			continue;
		}
		int group = (tp[1][i] == "nor" || tp[1][i] == "and");
		string tp_cur[2] = {tp[0][inp[1][i][0]], tp[0][inp[1][i][1]]};
		if(tp_cur[0] == "n"+tp_cur[1] || tp_cur[1] == "n"+tp_cur[0]) {
			if(num_inputs == 3) {
				del[i] = true;
				continue;
			}
			// num_inputs == 2
			has_ok[group] = true;
			res[group].push_back(i);
			continue;
		}
		if(tp[1][i][0] == 'n') {
			if(tp_cur[0] == "and" || tp_cur[1] == "and") {
				del[i] = true;
				continue;
			}
		}
		else {
			if(tp_cur[0] == "or" || tp_cur[1] == "or") {
				del[i] = true;
				continue;
			}
		}
		res[group].push_back(i);
		if(num_inputs == 2) {
			for(int j = 0; j < N[0]; j++) if(inputs[j]) {
				for(int k = j+1; k < N[0]; k++) if(inputs[k])
					G[group][2*j][2*k+1] = G[group][2*k][2*j+1] = G[group][2*j+1][2*k] = G[group][2*k+1][2*j] = 1;
				break;
			}
			continue;
		}
		// num_inputs == 3
		for(int j = 0; j < N[0]; j++) if(inputs[j] == 2)
			for(int k = 0; k < N[0]; k++) if(inputs[k] == 1) {
				for(int l = k+1; l < N[0]; l++) if(inputs[l] == 1) {
					int id_gor = (tp_cur[0] == "or" || tp_cur[0] == "nor") ? inp[1][i][0] : inp[1][i][1];
					int inp1 = inp[0][id_gor][0]+inp[0][id_gor][1]-j;
					int inp0 = k+l-inp1;
					G[group][2*inp1][2*inp0] = G[group][2*inp0+1][2*inp1+1] = 1;
					G[group][2*inp1][2*j+1] = G[group][2*j][2*inp1+1] = 1;
					G[group][2*inp0+1][2*inp1+1] = G[group][2*inp1][2*inp0] = 1;
					G[group][2*inp0+1][2*j] = G[group][2*j+1][2*inp0] = 1;
				}
				break;
			}
	}
	int ans = 0;
	for(int k = 0; k < 2; k++) {
		if(has_ok[k]) {
			ans = max(ans, (int)res[k].size());
			continue;
		}
		bool fails = true;
		for(int i = 0; i < N[0]; i++) {
			bool reach[2] = {false, false};
			for(int b = 0; b < 2; b++) {
				queue<int> q;
				vector<int> vis(2*N[0], 0);
				vis[2*i+b] = 1;
				q.push(2*i+b);
				while(!q.empty()) {
					for(int j = 0; j < 2*N[0]; j++) if(G[k][q.front()][j] && vis[j] == 0) {
						vis[j] = 1;
						q.push(j);
					}
					q.pop();
				}
				if(vis[2*i]) reach[b] = true;
			}
			if(reach[0] && reach[1]) fails = false;
		}
		if(!fails) ans = max(ans, (int)res[k].size());
	}
	cout << ((ans == 0) ? -1 : (N[2]-ans)) << "\n";
	return 0;
}

// look at my code
// my code is amazing