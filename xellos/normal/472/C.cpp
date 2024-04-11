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
#define soclose 1e-9
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define lng long long
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector< pair<string,string> > S(N);
	for(int i =0; i < N; i++) {
		cin >> S[i].ff >> S[i].ss;
		if(S[i].ff > S[i].ss) swap(S[i].ff,S[i].ss);}
	int p;
	string last ="";
	for(int i =0; i < N; i++) {
		cin >> p; p--;
		if(S[p].ff > last) last =S[p].ff;
		else if(S[p].ss > last) last =S[p].ss;
		else {cout << "NO\n"; return 0;}
		}
	cout << "YES\n";
	return 0;}

// look at my code
// my code is amazing