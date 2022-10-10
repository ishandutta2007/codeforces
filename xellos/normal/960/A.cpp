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

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	string S;
	cin >> S;
	int a = 0;
	while(a < (int)S.length() && S[a] == 'a') a++;
	int b = a;
	while(b < (int)S.length() && S[b] == 'b') b++;
	int c = b;
	while(c < (int)S.length() && S[c] == 'c') c++;
	if(a > 0 && b > a && c == (int)S.length() && (c-b == a || c-b == b-a)) cout << "YES\n";
	else cout << "NO\n";
	return 0;}

// look at my code
// my code is amazing