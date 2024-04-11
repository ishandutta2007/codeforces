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
	int Q;
	cin >> Q;
	vector<int> poc(1<<20,0);
	for(int i =0; i < Q; i++) {
		string s;
		cin >> s;
		if(s != "?") {
			long long x;
			cin >> x;
			int b =0, p =0;
			while(x > 0) {
				if(x%2 != 0) b |=1<<p;
				p++;
				x /=10;}
			if(s == "+") poc[b]++;
			else poc[b]--;
			continue;}
		cin >> s;
		int b =0;
		for(int i =0; i < (int)s.length(); i++) if(s[i] == '1') b |=1<<(s.length()-1-i);
		cout << poc[b] << "\n";}
	return 0;}

// look at my code
// my code is amazing