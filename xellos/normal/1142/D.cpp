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
	string S;
	cin >> S;
	int L = S.length();
	vector<int> seq_small(10), first_child(11, 10);
	for(int i = 0; i < 10; i++) {
		seq_small[i] = i;
		for(int j = 0; j < i; j++) seq_small.push_back(10*seq_small[i]+j);
		first_child[i+1] = seq_small.size();
	}
	vector<cat> cnt_mod(11, 0);
	cat ans = 0;
	for(int i = 0; i < L; i++) {
		vector<cat> cnt_mod_nxt(11, 0);
		for(int j = S[i]-'0'+1; j < 11; j++) {
			int nxt_mod = (first_child[j] + S[i]-'0') % 11;
			cnt_mod_nxt[nxt_mod] += cnt_mod[j];
		}
		cnt_mod = cnt_mod_nxt;
		if(S[i] != '0') cnt_mod[S[i]-'0']++;
		for(int j = 0; j < 11; j++) ans += cnt_mod[j];
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing