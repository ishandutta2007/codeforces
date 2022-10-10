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
#include <random>
#include <chrono>
#include <cstring>
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
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> A(N), occ(N+1, 0);
		for(int i = 0; i < N; i++) {
			cin >> A[i];
			occ[--A[i]]++;
		}
		bool ok = true;
		int l[2] = {0, 0};
		while(occ[l[1]] == 2) l[1]++;
		l[0] = l[1];
		while(occ[l[0]] == 1) l[0]++;
		for(int i = l[0]; i <= N; i++)
			if(occ[i]) ok = false;
		if(!ok || !l[0] || !l[1]) {
			cout << "0\n";
			continue;
		}
		vector< pair<int, int> > ans;
		for(int k = 0; k < ((l[0] == l[1]) ? 1 : 2); k++) {
			for(int i = 0; i < N; i++) occ[i] = 0;
			for(int i = 0; i < l[k]; i++) occ[A[i]]++;
			ok = true;
			for(int i = 0; i < l[k]; i++) if(occ[i] != 1) ok = false;
			if(!ok) continue;
			for(int i = 0; i < N; i++) occ[i] = 0;
			for(int i = N-1; i >= N-l[1-k]; i--) occ[A[i]]++;
			for(int i = 0; i < l[1-k]; i++) if(occ[i] != 1) ok = false;
			if(ok) ans.push_back({l[k], l[1-k]});
		}
		cout << ans.size() << "\n";
		for(auto p : ans) cout << p.ff << " " << p.ss << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing