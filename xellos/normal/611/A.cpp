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
	int mon[] ={31,29,31,30,31,30,31,31,30,31,30,31};
	int x;
	string s;
	cin >> x >> s;
	cin >> s;
	x--;
	int d =4, dm =0, m =0, ans =0;
	for(int i =0; i < 366; i++) {
		if(s[s.length()-1] == 'k' && d == x) ans++;
		if(s[s.length()-1] == 'h' && dm == x) ans++;
		d++;
		if(d >= 7) d -=7;
		dm++;
		if(dm >= mon[m]) {
			dm -=mon[m];
			m++;}
		}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing