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
	int N;
	cin >> N;
	vector<cat> B[100];
	for(int i = 0; i < N; i++) {
		cat b;
		cin >> b;
		for(int d = 1; d < 63; d++) if((1LL<<d) > b) {
			B[d-1].push_back(b);
			break;
		}
	}
	vector<cat> seq;
	for(int i = 70; i >= 0; i--) {
		int a = 0;
		vector<cat> seq_nw;
		bool move = false;
		for(int j = 0; j < (int)B[i].size(); j++) {
			if(move) {
				while(true) {
					if(a == (int)seq.size()) {
						cout << "No\n";
						return 0;
					}
					seq_nw.push_back(seq[a]);
					if((seq[a]>>i)&1) {
						a++;
						break;
					}
					a++;
				}
			}
			seq_nw.push_back(B[i][j]);
			move = true;
		}
		while(a < (int)seq.size()) {
			seq_nw.push_back(seq[a]);
			a++;
		}
		seq = seq_nw;
	}
	cout << "Yes\n";
	for(int i = 0; i < N; i++) cout << seq[i] << ((i == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing