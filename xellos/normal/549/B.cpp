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
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265359
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<string> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];

	vector<int> ans;
	for(int k =0; k < N; k++) {
		for(int i =0; i < N; i++) if(A[i] == 0) {
			for(int j =0; j < N; j++) 
				if(V[i][j] == '1') A[j]--;
			ans.push_back(i);}
		}

	cout << ans.size() << "\n";
	for(uint i =0; i < ans.size(); i++) cout << ans[i]+1 << ((i+1 == ans.size())?"\n":" ");
	return 0;}

// look at my code
// my code is amazing