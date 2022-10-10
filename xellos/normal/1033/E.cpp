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

int query(vector<int> & s) {
	cout << "? " << s.size() << "\n";
	for(int i = 0; i < (int)s.size(); i++) cout << s[i]+1 << ((i+1 == (int)s.size()) ? "" : " ");
	cout << endl;
	int res;
	cin >> res;
	return res;
}

void answer(bool bipartite, vector<int> & vertices) {
	cout << (bipartite ? "Y " : "N ") << vertices.size() << "\n";
	for(int i = 0; i < (int)vertices.size(); i++) cout << vertices[i]+1 << ((i+1 == (int)vertices.size()) ? "" : " ");
	cout << endl;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> part[2];
	part[0].push_back(0);
	vector<bool> unused(N, true);
	unused[0] = false;
	vector<int> last_id(N, 0);
	int E = 0;
	for(int i = 0; i < N-1; i++) {
		vector<int> cand;
		for(int j = 0; j < N; j++) if(unused[j]) cand.push_back(j);
		while((int)cand.size() > 1) {
			vector<int> cand1, cand2;
			for(int j = 0; j < (int)cand.size(); j++) {
				if(j < (int)cand.size()-j) cand1.push_back(cand[j]);
				else cand2.push_back(cand[j]);
			}
			int e = query(cand1);
			vector<int> s = cand1;
			for(int j = 0; j < N; j++) if(!unused[j]) s.push_back(j);
			int e1 = query(s);
			if(e1 == E+e) cand = cand2;
			else cand = cand1;
		}
		unused[cand[0]] = false;
		vector<int> s[2] = {part[0], part[1]};
		int e[2];
		for(int j = 0; j < 2; j++) {
			s[j].push_back(cand[0]);
			e[j] = query(s[j]);
		}
		if(e[0] == 0 || e[1] == 0) {
			if(e[0] == 0) {
				part[0].push_back(cand[0]);
				last_id[cand[0]] = part[1].size();
			}
			else {
				part[1].push_back(cand[0]);
				last_id[cand[0]] = part[0].size();
			}
			E += e[0]+e[1];
			continue;
		}
		// odd-length cycle
		vector<int> path[2]; // cand[0]..0
		for(int k = 0; k < 2; k++) {
			path[k].push_back(cand[0]);
			last_id[cand[0]] = part[1-k].size();
			int pid = 1-k;
			while(path[k].back() != 0) {
				int v = path[k].back();
				vector<int> c;
				for(int j = 0; j < last_id[v]; j++) c.push_back(part[pid][j]);
				while((int)c.size() > 1) {
					vector<int> c1, c2;
					for(int j = 0; j < (int)c.size(); j++) {
						if(j < (int)c.size()-j) c1.push_back(c[j]);
						else c2.push_back(c[j]);
					}
					vector<int> s = c1;
					s.push_back(v);
					if(query(s) == 0) c = c2;
					else c = c1;
				}
				path[k].push_back(c[0]);
				pid = 1-pid;
			}
		}
		while(path[0].back() == path[1].back()) {
			int sz0 = path[0].size(), sz1 = path[1].size();
			if(sz0 >= 2 && sz1 >= 2 && path[0][sz0-2] == path[1][sz1-2]) {
				path[0].pop_back();
				path[1].pop_back();
			}
			else break;
		}
		vector<int> cyc = path[0];
		for(int j = (int)path[1].size()-2; j > 0; j--) cyc.push_back(path[1][j]);
		answer(false, cyc);
		return 0;
	}
	answer(true, part[0]);
	return 0;
}

// look at my code
// my code is amazing