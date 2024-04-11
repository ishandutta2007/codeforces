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
#define in(a,b) ((a>>b)&1)
#define notin(a,b) (((a>>b)&1) == 0)
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
	long long X;
	cin >> X;
	vector< pair<long long,long long> > ans;
	for(long long i =1; i < 1500000; i++) {
		long long x =X-(2*i+1)*(i+1)*i/6;
		if(x < 0) break;
		long long y =(i+1)*i/2;
		if(x%y != 0) continue;
		ans.push_back(make_pair(i,x/y+i));}
	if(!ans.empty() && ans.back().ff == ans.back().ss) cout << ans.size()*2-1 << "\n";
	else cout << ans.size()*2 << "\n";
	ALL_THE(ans,it) cout << it->ff << " " << it->ss << "\n";
	for(int i =ans.size()-1; i >= 0; i--) if(ans[i].ff != ans[i].ss)
		cout << ans[i].ss << " " << ans[i].ff << "\n";
	return 0;}

// look at my code
// my code is amazing