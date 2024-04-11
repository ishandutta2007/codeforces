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
#define OVER9000 1234567890123456789LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

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
	if((N/2)%2 != 0) {
		cout << "! -1" << endl;
		return 0;
	}
	int a, b;
	cout << "? 1" << endl;
	cin >> a;
	cout << "? " << N/2+1 << endl;
	cin >> b;
	int dif_l = b-a, dif_r = a-b;
	if(dif_l == 0) {
		cout << "! 1" << endl;
		return 0;
	}
	int l = 1, r = N/2+1;
	while(r-l > 1) {
		int c = (l+r)/2;
		cout << "? " << c << endl;
		cin >> a;
		cout << "? " << c+N/2 << endl;
		cin >> b;
		int dif = b-a;
		if(dif == 0) {
			cout << "! " << c << endl;
			return 0;
		}
		if((dif > 0) == (dif_l > 0)) {
			dif_l = dif;
			l = c;
		}
		else {
			dif_r = dif;
			r = c;
		}
	}
	return 0;
}

// look at my code
// my code is amazing