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
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	sort(begin(A),end(A));
	vector<double> pr1(5000+tisic,0);
	for(int i =0; i < N; i++) for(int j =0; j < i; j++) pr1[A[i]-A[j]] +=2.0/N/(N-1);
	vector<double> pr2(10000+tisic,0);
	for(int i =0; i <= 5000; i++) for(int j =0; j <= 5000; j++)
		pr2[i+j] +=pr1[i]*pr1[j];
	double ans =0;
	for(int i =0; i <= 5000; i++) for(int j =0; j < i; j++)
		ans +=pr1[i]*pr2[j];
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing