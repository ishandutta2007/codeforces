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
	string ans;
	vector< pair<int, int> > seq = {{1, 1}};
	for(int i = 0; i < N-1; i++) {
		pair<int, int> p = seq.back();
		if(p.ff < N) p.ff++;
		else p.ss++;
		char dir;
		if(p.ff != seq.back().ff) dir = 'D';
		else dir = 'R';
		cout << "? " << p.ff << " " << p.ss << " " << N << " " << N << endl;
		string s;
		cin >> s;
		if(s == "YES") {
			seq.push_back(p);
			ans += dir;
		}
		else {
			if(p.ff == seq.back().ff) p.ff++, p.ss--;
			else p.ff--, p.ss++;
			seq.push_back(p);
			if(dir == 'R') ans += 'D';
			else ans += 'R';
		}
	}
	vector< pair<int, int> > iseq = {{N, N}};
	for(int i = 0; i < N-1; i++) {
		pair<int, int> p = iseq.back();
		p.ss--;
		if(p.ss < seq[N-1].ss) p.ss++, p.ff--;
		cout << "? " << seq[N-2-i].ff << " " << seq[N-2-i].ss << " " << p.ff << " " << p.ss << endl;
		string s;
		cin >> s;
		if(s == "YES") iseq.push_back(p);
		else {
			if(p.ss == iseq.back().ss) p.ss--, p.ff++;
			else p.ss++, p.ff--;
			iseq.push_back(p);
		}
	}
	reverse(begin(iseq), end(iseq));
	for(int i = 0; i < N-1; i++) {
		if(iseq[i+1].ff == iseq[i].ff) ans += 'R';
		else ans += 'D';
	}
	cout << "! " << ans << endl;
	return 0;
}

// look at my code
// my code is amazing