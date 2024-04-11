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
#define soclose 1e-5
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
	int N,M;
	cin >> N >> M;
	vector<string> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	int ans =0;
	for(int i =1; i < N; i++) for(int j =1; j < M; j++) {
		set<char> S;
		S.insert(V[i-1][j-1]);
		S.insert(V[i-1][j]);
		S.insert(V[i][j-1]);
		S.insert(V[i][j]);
		if(S.find('a') != S.end() && S.find('f') != S.end() && S.find('c') != S.end() && S.find('e') != S.end())
			ans++;
		}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing