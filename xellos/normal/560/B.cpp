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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int a1,b1,a2,b2,a3,b3;
	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
	for(int k =0; k < 2; k++) {
		for(int j =0; j < 2; j++) {
			if(a1 >= a2+a3 && b1 >= max(b2,b3)) {cout << "YES\n"; return 0;}
			if(b1 >= b2+b3 && a1 >= max(a2,a3)) {cout << "YES\n"; return 0;}
			swap(a3,b3);}
		swap(a2,b2);}
	cout << "NO\n";
	return 0;}

// look at my code
// my code is amazing