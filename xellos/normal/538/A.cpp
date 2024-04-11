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
	string s;
	cin >> s;
	int N =s.length();
	for(int l =0; l <= N; l++) for(int j =0; j <= N; j++) if(l+j < N) {
		string s1 =s.substr(0,l), s2 =s.substr(N-j,j);
		if(s1+s2 == "CODEFORCES") {cout << "YES\n"; return 0;}
		}
	cout << "NO\n";
	return 0;}

// look at my code
// my code is amazing