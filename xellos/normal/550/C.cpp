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
	for(int i =N-1; i >= 0; i--) if(S[i] == '0' || S[i] == '8') {
		cout << "YES\n" << S[i] << "\n";
		return 0;}
	for(int i =N-1; i >= 0; i--) for(int j =i-1; j >= 0; j--) {
		int x =10*(S[j]-'0')+S[i]-'0';
		if(x%8 != 0) continue;
		cout << "YES\n";
		cout << S[j] << S[i] << "\n";
		return 0;}
	for(int i =N-1; i >= 0; i--) if((S[i]-'0')%2 == 0)
		for(int j =i-1; j >= 0; j--) for(int k =j-1; k >= 0; k--) {
			int x =100*(S[k]-'0')+10*(S[j]-'0')+S[i]-'0';
			if(x%8 != 0) continue;
			cout << "YES\n";
			cout << S[k] << S[j] << S[i] << "\n";
			return 0;}
	cout << "NO\n";
	return 0;}

// look at my code
// my code is amazing