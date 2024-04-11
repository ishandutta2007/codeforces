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
	// B <-> C
	// B, C -> AB, AC
	// target has <= A-s at the end than origin
	// target has +2k B+C-s than origin
	int Q;
	string So, St, ans;
	cin >> So >> St >> Q;

	int Lo = So.length(), Lt = St.length();
	vector<int> R0o(Lo, 0), R0t(Lt, 0);
	for(int i = 0; i < Lo; i++)
		if(So[i] == 'A') R0o[i] = (i == 0 ? 0 : R0o[i-1]) + 1;
	for(int i = 0; i < Lt; i++)
		if(St[i] == 'A') R0t[i] = (i == 0 ? 0 : R0t[i-1]) + 1;
	vector<int> cnt1o(Lo+1, 0), cnt1t(Lt+1, 0);
	for(int i = 0; i < Lo; i++)
		cnt1o[i+1] = cnt1o[i] + (So[i] != 'A');
	for(int i = 0; i < Lt; i++)
		cnt1t[i+1] = cnt1t[i] + (St[i] != 'A');

	for(int q = 0; q < Q; q++) {
		int lo, ro, lt, rt;
		cin >> lo >> ro >> lt >> rt;
		lo--, lt--;

		int cnto[2] = {min(ro-lo, R0o[ro-1]), cnt1o[ro]-cnt1o[lo]};
		int cntt[2] = {min(rt-lt, R0t[rt-1]), cnt1t[rt]-cnt1t[lt]};
/*		for(int i = ro-1; i >= lo; i--) {
			if(So[i] != 'A') break;
			cnto[0]++;
		}
		for(int i = rt-1; i >= lt; i--) {
			if(St[i] != 'A') break;
			cntt[0]++;
		}
		for(int i = ro-1; i >= lo; i--)
			if(So[i] != 'A') cnto[1]++;
		for(int i = rt-1; i >= lt; i--)
			if(St[i] != 'A') cntt[1]++;
		cerr << cnto[0] << " " << cntt[0] << "\n";
		cerr << cnto[1] << " " << cntt[1] << "\n";
*/
                if(cnto[1] == 0 && cnto[0] == cntt[0] && cntt[1] != 0) {
			ans += '0';
			continue;
		}
		if(cnto[0] < cntt[0] || cnto[1] > cntt[1] || (cnto[1]-cntt[1])%2 != 0) {
			ans += '0';
			continue;
		}
		if(cntt[1] != cnto[1]) ans += '1';
		else if((cntt[0]-cnto[0])%3 == 0) ans += '1';
		else ans += '0';
	}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing