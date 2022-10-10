// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-11
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	vector<int> A0 =A;
	set<int> L;
	for(int i =0; i < N; i++) L.insert(i);

	int M;
	cin >> M;
	for(int q =0; q < M; q++) {
		int t; cin >> t;
		if(t == 2) {
			int a; cin >> a;
			if(L.find(--a) == L.end()) cout << A0[a] << "\n";
			else cout << A0[a]-A[a] << "\n";
			continue;}
		int a,b;
		cin >> a >> b;
		a--;
		auto it =L.lower_bound(a);
		while(b > 0 && it != L.end()) {
			int x =min(b,A[*it]);
			b -=x; A[*it] -=x;
			if(b > 0) {
				auto jt =it;
				it++;
				L.erase(jt);}}
		}
	return 0;}

// look at my code
// my code is amazing