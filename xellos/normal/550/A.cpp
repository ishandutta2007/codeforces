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
	string S;
	cin >> S;
	int N =S.length();
	set<int> s1,s2;
	for(int i =1; i < N; i++) {
		if(S[i] == 'B' && S[i-1] == 'A') s1.insert(i-1);
		if(S[i] == 'A' && S[i-1] == 'B') s2.insert(i-1);}
	if(s2.size() > patkan && s1.size() > patkan) {
		cout << "YES\n";
		return 0;}
	ALL_THE(s1,it) ALL_THE(s2,jt)
		if(abs(*it-*jt) > 1) {
			cout << "YES\n";
			return 0;}
	cout << "NO\n";
	return 0;}

// look at my code
// my code is amazing