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
	vector<long long> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	for(int i =1; i < N; i++) A[i] +=A[i-1];

	long long ans =1+(A[N-1]-A[N-2])*(A[N-1]-A[N-2]);
	int K =50;
	map<long long,int> M;
	for(int i =0; i < N; i++) {
		auto jt =M.lower_bound(A[i]);
		auto it =jt;
		int k =0;
		while(it != M.end()) {
			k++;
			if(k > K) break;
			ans =min(ans,1LL*(it->ss-i)*(it->ss-i)+(it->ff-A[i])*(it->ff-A[i]));
			if((it->ff-A[i])*(it->ff-A[i]) > ans) break;
			it++;}
		it =jt;
		k =0;
		while(it != M.begin()) {
			k++;
			if(k > K) break;
			it--;
			ans =min(ans,1LL*(it->ss-i)*(it->ss-i)+(it->ff-A[i])*(it->ff-A[i]));
			if((it->ff-A[i])*(it->ff-A[i]) > ans) break;}
		M[A[i]] =i;}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing