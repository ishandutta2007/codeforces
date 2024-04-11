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
#define OVER9000 1234567890123456LL
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
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	sort(A.begin(),A.end());
	if(A[N-1] != N) {cout << "NO\n"; return 0;}
	if(N == 1) {cout << "YES\n"; return 0;}

	multiset<int> roots;
	for(int i =0; i < N; i++) {
		if(A[i] == 2) {cout << "NO\n"; return 0;}
		if(A[i] == 1 && i+1 < N && A[i+1] != 1) {
			roots.insert((1<<(i+1))-1);
			continue;}
		if(i+1 < N && A[i+1] == 1) continue;
		// vyber sucet A[i]-1
		multiset<int> rootsN;
		ALL_THE(roots,it) {
			vector<int> R;
			for(int j =0; j < N; j++) if(((*it)&(1<<j)) != 0) R.push_back(j);
			bool in =true;
			for(int j =0; j < R.size(); j++) if(A[R[j]] == 1 && R[j] != j) {
				in =false;
				break;}
			if(!in) continue;
			int r =R.size();
			for(int k =0; k < (1<<r); k++) {
				int s =0, d =0;
				for(int j =0; j < r; j++)
					if((k&(1<<j)) != 0) s +=(A[R[j]] == A[i]-1)?A[i]:A[R[j]];
					else d |=(1<<R[j]);
				if(s == A[i]-1) rootsN.insert((1<<i)|d);}
			}
		roots =rootsN;}

	if(roots.find(1<<(N-1)) == roots.end()) cout << "NO\n";
	else cout << "YES\n";
	return 0;}

// look at my code
// my code is amazing