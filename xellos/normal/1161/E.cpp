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
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		if(N == -1) return 0;
		if(N == 1) {
			cout << "A 0 0 1\n\n\n1" << endl;
			continue;
		}
		cout << "Q " << N/2;
		for(int i = 0; i < N/2; i++) cout << " " << i+1 << " " << N/2+i+1;
		cout << endl;
		string ans;
		cin >> ans;
		vector< vector< vector<int> > > dg;
		vector< vector<int> > eg;
		for(int i = 0; i < N/2; i++) {
			if(ans[i] == '0') dg.push_back({{i}, {N/2+i}, {}});
			else eg.push_back({i, N/2+i});
		}
		if(N&1) eg.push_back({N-1});
		if((int)eg.size() > 1) {
			cout << "Q " << eg.size()-1;
			for(int i = 0; i < (int)eg.size()-1; i++)
				cout << " " << eg[i][1]+1 << " " << eg[i+1][0]+1;
			cout << endl;
			cin >> ans;
			vector<int> eg_rem = eg.back();
			vector<int> eg_prev;
			for(int i = (int)eg.size()-2; i >= 0; i--) {
				if(ans[i] == '1') {
					ALL_THE(eg[i], it) eg_rem.push_back(*it);
					continue;
				}
				if(!eg_prev.empty()) {
					dg.push_back({eg_prev, eg_rem, {}});
					eg_prev.clear();
				}
				else eg_prev = eg_rem;
				eg_rem.clear();
				ALL_THE(eg[i], it) eg_rem.push_back(*it);
			}
			eg.clear();
			if(!eg_prev.empty()) dg.push_back({eg_prev, eg_rem, {}});
			else eg.push_back(eg_rem);
		}
		// eg.size() <= 1
		if((int)eg.size() == 1) {
			if(dg.empty()) {
				cout << "A 0 0 " << N << "\n\n\n";
				for(int i = 0; i < N; i++) cout << i+1 << ((i == N-1) ? "" : " ");
				cout << endl;
				continue;
			}
			if((int)eg[0].size() == 1) {
				cout << "Q 1 " << dg[0][0][0]+1 << " " << eg[0][0]+1 << endl;
				cin >> ans;
				if(ans == "1") dg[0][0].push_back(eg[0][0]);
				else {
					cout << "Q 1 " << dg[0][1][0]+1 << " " << eg[0][0]+1 << endl;
					cin >> ans;
					if(ans == "1") dg[0][1].push_back(eg[0][0]);
					else dg[0][2].push_back(eg[0][0]);
				}
			}
			else {
				cout << "Q 2 " << dg[0][0][0]+1 << " " << eg[0][0]+1 << " "
					<< dg[0][1][0]+1 << " " << eg[0][1]+1 << endl;
				cin >> ans;
				if(ans[0] == '1') {
					ALL_THE(eg[0], it) dg[0][0].push_back(*it);
				}
				else if(ans[1] == '1') {
					ALL_THE(eg[0], it) dg[0][1].push_back(*it);
				}
				else {
					ALL_THE(eg[0], it) dg[0][2].push_back(*it);
				}
			}
		}
		int D = dg.size();
		vector< vector<int> > dg_eq(D, vector<int>(3));
		for(int k = 0; k < 2; k++) {
			int c = 0;
			for(int i = k; i < D-1; i += 2) c++;
			if(c == 0) continue;
			cout << "Q " << 2*c;
			vector<int> last_f;
			for(int i = k; i < D-1; i += 2) {
				cout << " " << dg[i][0][0]+1 << " " << dg[i+1][0][0]+1;
				cout << " " << dg[i][1][0]+1 << " " << dg[i+1][1][0]+1;
				last_f.push_back(0);
			}
			cout << endl;
			cin >> ans;
			c = 0;
			bool needs_q = false;
			for(int i = k; i < D-1; i += 2) {
				if(ans[2*c] == '1' && ans[2*c+1] == '1') {
					dg_eq[i][0] = 0;
					dg_eq[i][1] = 1;
					dg_eq[i][2] = 2;
				}
				else if(ans[2*c] == '0' && ans[2*c+1] == '1') {
					dg_eq[i][1] = 1;
					dg_eq[i][0] = 2;
					dg_eq[i][2] = 0;
				}
				else if(ans[2*c] == '1' && ans[2*c+1] == '0') {
					dg_eq[i][0] = 0;
					dg_eq[i][1] = 2;
					dg_eq[i][2] = 1;
				}
				else last_f[c] = 1, needs_q = true;
				c++;
			}
			if(!needs_q) continue;
			int d = c = 0;
			for(int i = k; i < D-1; i += 2) {
				if(last_f[c]) d++;
				c++;
			}
			cout << "Q " << 2*d;
			d = c = 0;
			for(int i = k; i < D-1; i += 2) {
				if(last_f[c]) {
					cout << " " << dg[i][0][0]+1 << " " << dg[i+1][1][0]+1;
					cout << " " << dg[i][1][0]+1 << " " << dg[i+1][0][0]+1;
				}
				c++;
			}
			cout << endl;
			cin >> ans;
			c = 0;
			for(int i = k; i < D-1; i += 2) {
				if(last_f[c]) {
					if(ans[2*d] == '1' && ans[2*d+1] == '1') {
						dg_eq[i][0] = 1;
						dg_eq[i][1] = 0;
						dg_eq[i][2] = 2;
					}
					else if(ans[2*d] == '0') {
						dg_eq[i][0] = 2;
						dg_eq[i][1] = 0;
						dg_eq[i][2] = 1;
					}
					else {
						dg_eq[i][1] = 2;
						dg_eq[i][0] = 1;
						dg_eq[i][2] = 0;
					}
					d++;
				}
				c++;
			}
		}
		vector<int> g[3];
		int cur[3] = {0, 1, 2};
		for(int i = 0; i < D; i++) {
			for(int j = 0; j < 3; j++) ALL_THE(dg[i][j], it)
				g[cur[j]].push_back(*it);
			if(i < D-1) {
				int cur_nw[3];
				for(int j = 0; j < 3; j++) cur_nw[dg_eq[i][j]] = cur[j];
				for(int j = 0; j < 3; j++) cur[j] = cur_nw[j];
			}
		}
		cout << "A " << g[0].size() << " " << g[1].size() << " " << g[2].size() << "\n";
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < (int)g[j].size(); k++)
				cout << g[j][k]+1 << ((k+1 == (int)g[j].size()) ? "" : " ");
			cout << endl;
		}
	}
	return 0;
}

// look at my code
// my code is amazing