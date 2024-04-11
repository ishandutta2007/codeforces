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

void generate_paths(int N, vector<int> ids, vector< vector<int> > & paths) {
	if(N == 4) {
		paths.push_back({ids[0], ids[1], ids[2]});
		paths.push_back({ids[1], ids[3], ids[2]});
		paths.push_back({ids[3], ids[0], ids[2]});
		return;
	}
	for(int i = 0; i < N/4; i++) for(int j = 0; j < N/4; j++) {
		paths.push_back({ids[2*i], ids[N/2+2*j], ids[2*i+1]});
		paths.push_back({ids[2*i], ids[N/2+2*j+1], ids[2*i+1]});
	}
	vector<int> ids_l, ids_r;
	for(int i = 0; i < N/2; i++) ids_l.push_back(ids[i]);
	for(int i = 0; i < N/2; i++) ids_r.push_back(ids[i+N/2]);
	generate_paths(N/2, ids_l, paths);
	generate_paths(N/2, ids_r, paths);
}

int q_cnt = 0;

bool ask(int q) {
	q_cnt++;
	cout << "? " << q+1 << endl;
	string ans;
	cin >> ans;
	return ans == "Y";
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, K;
	cin >> N >> K;
	vector<char> live(N, 1);
	if(K == 1) {
		for(int i = 0; i < N; i++) for(int j = 0; j < i; j++) if(i != j) {
			if(!live[i] || !live[j]) continue;
			ask(i);
			if(ask(j)) live[j] = false;
		}
	}
	else if(K == N) {
		for(int i = 0; i < N; i++)
			if(ask(i)) live[i] = false;
	}
	else {
		K /= 2;
		int B = N/K;
		vector< vector<int> > paths;
		vector<int> ids(B);
		for(int i = 0; i < B; i++) ids[i] = i;
		generate_paths(B, ids, paths);
		for(auto path : paths) {
			for(auto b : path)
				for(int j = 0; j < K; j++) if(live[b*K+j])
					if(ask(b*K+j)) live[b*K+j] = 0;
			cout << "R" << endl;
		}
	}
	int ans = 0;
	for(int i = 0; i < N; i++) ans += live[i];
	cout << "! " << ans << endl;
	return 0;
}

// look at my code
// my code is amazing