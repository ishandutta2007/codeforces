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
	int N;
	cin >> N;
	int minsum = 2*N+10;
	for(int lis = 1; lis <= N; lis++)
		for(int lds = 1; lds <= N; lds++) if(lds * lis >= N) {
			minsum = min(minsum, lis+lds);
			break;
		}
	for(int lis = 1; lis <= N; lis++)
		for(int lds = 1; lds <= N; lds++) if(lds * lis >= N) {
			if(lis+lds == minsum) {
				vector<int> P;
				for(int i = 0; i < lis; i++) for(int j = 0; j < lds; j++)
					P.push_back(i*lds+lds-1-j);
				P.resize(N);
				map<int, int> MP;
				for(int i = 0; i < N; i++) MP[P[i]] = 0;
				int m = 0;
				ALL_THE(MP, it) it->ss = m++;
				for(int i = 0; i < N; i++) cout << MP[P[i]]+1 << ((i == N-1) ? "\n" : " ");
				return 0;
			}
			break;
		}
	return 0;
}

// look at my code
// my code is amazing