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
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) {
		cin >> A[i];
		A[i] -=i;}
	vector< map<int,long long> > ans(N+1);
	ans[0][-N] =0;
	for(int i =0; i < N; i++) {
		long long x =1e18;
		ALL_THE(ans[i],it) {
			x =min(x,it->ss);
			it->ss =x;}
		long long sumL =0, sumR =0;
		multiset<int> sL,sR;
		for(int j =i; j < N; j++) {
			sumL +=A[j];
			sL.insert(A[j]);
			while(sL.size() > sR.size()) {
				sumR +=*sL.rbegin();
				sumL -=*sL.rbegin();
				sR.insert(*sL.rbegin());
				sL.erase(--sL.end());}
			while(!sL.empty() && !sR.empty() && *sL.rbegin() > *sR.begin()) {
				long long a =*sL.rbegin(), b =*sR.begin();
				sL.erase(--sL.end());
				sR.erase(sR.begin());
				sumL +=b-a, sumR +=a-b;
				sL.insert(b);
				sR.insert(a);}
			long long cent =*sR.begin();
			long long cost =cent*sL.size()-sumL+sumR-cent*sR.size();
			auto it =ans[i].upper_bound(cent);
			if(it == ans[i].begin()) continue;
			it--;
			auto jt =ans[j+1].find(cent);
			if(jt == ans[j+1].end()) ans[j+1][cent] =it->ss+cost;
			else jt->ss =min(jt->ss,it->ss+cost);}
		}
	long long ansF =1e18;
	ALL_THE(ans[N],it) ansF =min(ansF,it->ss);
	cout << ansF << "\n";
	return 0;}

// look at my code
// my code is amazing