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
	vector< pair<int, int> > P(N);
	for(int i = 0; i < N; i++) cin >> P[i].ff >> P[i].ss;
	int cnt_ps[] = {0, 0};
	for(int i = 0; i < N; i++) cnt_ps[(P[i].ff+P[i].ss)%2 == 0]++;
	if(cnt_ps[0] && cnt_ps[1]) {
		cout << cnt_ps[1] << "\n";
		bool st = true;
		for(int i = 0; i < N; i++) if((P[i].ff+P[i].ss)%2 == 0) {
			if(!st) cout << " ";
			st = false;
			cout << i+1;
		}
		cout << "\n";
		return 0;
	}
	if(cnt_ps[0]) for(int i = 0; i < N; i++) P[i].ss++;
	int cnt_p[2] = {0, 0};
	for(int i = 0; i < N; i++) cnt_p[P[i].ff%2 == 0]++;
	while(!cnt_p[0] || !cnt_p[1]) {
		if(cnt_p[0]) for(int i = 0; i < N; i++) P[i].ff++, P[i].ss++;
		for(int i = 0; i < N; i++) P[i].ff /= 2, P[i].ss /= 2;
		cnt_ps[0] = cnt_ps[1] = 0;
		for(int i = 0; i < N; i++) cnt_ps[(P[i].ff+P[i].ss)%2 == 0]++;
		if(cnt_ps[0] && cnt_ps[1]) {
			cout << cnt_ps[1] << "\n";
			bool st = true;
			for(int i = 0; i < N; i++) if((P[i].ff+P[i].ss)%2 == 0) {
				if(!st) cout << " ";
				st = false;
				cout << i+1;
			}
			cout << "\n";
			return 0;
		}
		if(cnt_ps[0]) for(int i = 0; i < N; i++) P[i].ss++;
		cnt_p[0] = cnt_p[1] = 0;
		for(int i = 0; i < N; i++) cnt_p[P[i].ff%2 == 0]++;
	}
	cout << cnt_p[1] << "\n";
	bool st = true;
	for(int i = 0; i < N; i++) if(P[i].ff%2 == 0) {
		if(!st) cout << " ";
		st = false;
		cout << i+1;
	}
	cout << "\n";
	return 0;
}

// look at my code
// my code is amazing