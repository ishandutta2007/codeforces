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
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int M,T,R;
	cin >> M >> T >> R;
	set<int> times;
	for(int i =-1000; i < 1000; i++) times.insert(i);
	set<int> ends;
	int ans =0;
	for(int i =0; i < M; i++) {
		int w;
		cin >> w;
		while(!ends.empty() && *ends.begin() <= w) ends.erase(ends.begin());
		while(ends.size() < R) {
			auto it =times.upper_bound(w);
			if(it == times.begin()) {cout << "-1\n"; return 0;}
			it--;
			if(*it+T <= w) {cout << "-1\n"; return 0;}
			ends.insert(*it+T);
			times.erase(it);
			ans++;}
		}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing