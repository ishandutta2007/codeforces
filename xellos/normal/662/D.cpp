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
	for(int i =0; i < N; i++) {
		string s;
		cin >> s;
		int L =s.length()-4;
		s =s.substr(4,L);
		set<long long> used;
		for(int i =L-1; i >= 0; i--) {
			string s2 =s.substr(i,L-i);
			long long x =0;
			if(s2[0] == '0') x++;
			while(true) {
				long long y =x;
				for(int j =0; j < L-i; j++) y =y*10+s2[j]-'0';
				if(y < 1989 || used.find(y) != used.end()) {
					x++; 
					continue;}
				used.insert(y);
				if(i == 0) cout << y << "\n";
				break;}
			}
		}
	return 0;}

// look at my code
// my code is amazing