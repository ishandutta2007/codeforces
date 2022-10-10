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
		vector< vector<int> > A(N, vector<int>(N));
		for(int i = 0; i < N*N; i++) cin >> A[i/N][i%N];
		cout << "B" << endl;
		string s;
		int v;
		cin >> s >> v;
		v--;
		vector< vector<int> > B(2*N, vector<int>(N));
		vector< vector<int> > val(2*N, vector<int>(2*N));
		for(int i = 0; i < N; i++) {
			vector< pair<int, int> > order;
			for(int j = 0; j < N; j++) {
				if((s == "I") == (v < N)) order.push_back({A[i][j], j+N});
				else order.push_back({N*N-A[i][j], j+N});
			}
			sort(begin(order), end(order));
			for(int j = 0; j < N; j++) {
				B[i][j] = order[j].ss;
				val[i][order[j].ss] = j;
			}
		}
		for(int i = 0; i < N; i++) {
			vector< pair<int, int> > order;
			for(int j = 0; j < N; j++) {
				if((s == "I") == (v < N)) order.push_back({N*N-A[j][i], j});
				else order.push_back({A[j][i], j});
			}
			sort(begin(order), end(order));
			for(int j = 0; j < N; j++) {
				B[i+N][j] = order[j].ss;
				val[i+N][order[j].ss] = j;
			}
		}
		vector<int> match(2*N, -1), proc(N, 0);
		while(true) {
			bool done = true;
			for(int i = 0; i < N; i++) if(match[i] == -1) {
				done = false;
				int j = B[i][proc[i]];
				assert(proc[i] < N);
				if(match[j] == -1) match[j] = i, match[i] = j;
				else if(val[j][match[j]] > val[j][i]) {
					match[match[j]] = -1;
					match[j] = i, match[i] = j;
				}
				proc[i]++;
			}
			if(done) break;
		}
		while(true) {
			cout << match[v]+1 << endl;
			cin >> v;
			if(v < 0) break;
			v--;
		}
	}
	return 0;
}

// look at my code
// my code is amazing