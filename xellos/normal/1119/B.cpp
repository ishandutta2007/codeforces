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
	cat H;
	cin >> N >> H;
	vector<int> A(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		vector<int> B(i+1);
		for(int j = 0; j <= i; j++) B[j] = A[j];
		sort(begin(B), end(B));
		reverse(begin(B), end(B));
		cat sumH = 0;
		for(int j = 0; j <= i; j += 2) sumH += B[j];
		if(sumH > H) {
			cout << i << "\n";
			return 0;
		}
	}
	cout << N << "\n";
	return 0;
}

// look at my code
// my code is amazing