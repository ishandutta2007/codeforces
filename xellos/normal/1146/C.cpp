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
		cout << "1 " << N-1 << " 1";
		for(int i = 0; i < N-1; i++) cout << " " << i+2;
		cout << endl;
		int d0;
		cin >> d0;
		vector<int> cand(N-1);
		for(int i = 0; i < N-1; i++) cand[i] = i+2;
		while((int)cand.size() > 1) {
			vector<int> c1, c2;
			for(int i = 0; i < (int)cand.size()/2; i++) c1.push_back(cand[i]);
			for(int i = (int)cand.size()/2; i < (int)cand.size(); i++) c2.push_back(cand[i]);
			cout << "1 " << c1.size() << " 1";
			ALL_THE(c1, it) cout << " " << *it;
			cout << endl;
			int d;
			cin >> d;
			if(d == d0) cand = c1;
			else cand = c2;
		}
		cout << "1 " << N-1 << " " << cand[0];
		for(int i = 0; i < N; i++) if(i+1 != cand[0]) cout << " " << i+1;
		cout << endl;
		int d1;
		cin >> d1;
		cout << "-1 " << d1 << endl;
	}
	return 0;
}

// look at my code
// my code is amazing