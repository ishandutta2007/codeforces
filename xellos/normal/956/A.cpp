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
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

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
	vector<string> V(N);
	for(int i = 0; i < N; i++) cin >> V[i];
	vector<bool> bl(M, 0), skip(N, 0);
	for(int i = 0; i < N; i++) if(!skip[i]) {
		vector<int> pos, rows;
		for(int j = 0; j < M; j++) if(V[i][j] == '#') {
			pos.push_back(j);
			if(bl[j]) {
				cout << "No\n";
				return 0;
			}
			if(rows.empty())
				for(int k = 0; k < N; k++) if(V[k][j] == '#') rows.push_back(k);
		}
		ALL_THE(rows, it) if(V[*it] != V[i]) {
			cout << "No\n";
			return 0;
		}
		ALL_THE(pos, it) bl[*it] = true;
		ALL_THE(rows, it) skip[*it] = true;
	}
	cout << "Yes\n";
	return 0;}

// look at my code
// my code is amazing