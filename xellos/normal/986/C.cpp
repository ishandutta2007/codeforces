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
	int N, M;
	cin >> N >> M;
	vector<int> A(M);
	vector<int> occ(1<<N, 0);
	for(int i = 0; i < M; i++) cin >> A[i];

	vector<int> sub0(1<<N, 0);
	for(int i = 0; i < M; i++) sub0[A[i]]++;
	vector<int> sub = sub0;
	for(int i = 0; i < N; i++) {
		vector<int> sub_nw(1<<N, 0);
		for(int j = 0; j < (1<<N); j++) {
			if((j>>i)&1) sub_nw[j] = sub[j] + sub[j^(1<<i)];
			else sub_nw[j] = sub[j];
		}
		sub = sub_nw;
	}

	for(int i = 0; i < (1<<N); i++) if(sub0[i]) {
		for(int j = 0; j < N; j++) {
			if((i>>j)&1) continue;
			if(sub[(1<<N)-1-i-(1<<j)] == 0) continue;
			sub0[i^(1<<j)] = 1;
		}
	}

	vector<int> comp(1<<N, -1);
	queue<int> q;
	int C = 0;
	vector<int> G;
	for(int i = 0; i < (1<<N); i++) if(comp[i] == -1 && sub0[i]) {
		q.push(i);
		comp[i] = C;
		while(!q.empty()) {
			G.clear();
			if(sub0[(1<<N)-1-q.front()] > 0 && sub0[q.front()] > 0)
				G.push_back((1<<N)-1-q.front());
			for(int j = 0; j < N; j++) {
				if((q.front()>>j)&1) {
					if(sub[(1<<N)-1-q.front()] != 0 && sub0[q.front()^(1<<j)] > 0)
						G.push_back(q.front()^(1<<j));
				}
				else {
					if(sub[(1<<N)-1-q.front()-(1<<j)] != 0)
						G.push_back(q.front()^(1<<j));
				}
			}
			ALL_THE(G, it) if(comp[*it] == -1) {
				comp[*it] = C;
				q.push(*it);
			}
			q.pop();
		}
		C++;
	}

	cout << C << "\n";
	return 0;}

// look at my code
// my code is amazing