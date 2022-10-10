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
#define OVER9000 1234567890LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
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
	int N,K;
	cin >> N >> K;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	int ans =-OVER9000;
	for(int i =0; i < N; i++) for(int j =i; j < N; j++) {
		multiset<int> S,T;
		for(int k =0; k < i; k++) S.insert(A[k]);
		for(int k =j+1; k < N; k++) S.insert(A[k]);
		for(int k =i; k <= j; k++) T.insert(A[k]);
		for(int k =0; k < K; k++) {
			if(S.empty() || T.empty()) break;
			if(*S.rbegin() > *T.begin()) {
				T.insert(*S.rbegin());
				S.insert(*T.begin());
				T.erase(T.begin());
				S.erase(--S.end());}
			else break;}
		int akt =0;
		ALL_THE(T,it) akt +=*it;
		ans =max(ans,akt);}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing