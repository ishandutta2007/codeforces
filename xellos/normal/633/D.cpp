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
	vector<long long> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	sort(begin(A),end(A));
	vector<int> pos(N);
	vector< pair<long long,int> > Ap;
	for(int i =0; i < N; i++) if(i == 0 || A[i] != A[i-1]) {
		int x =0;
		for(int j =i; j < N; j++) {
			if(A[j] != A[i]) break;
			x++;}
		for(int j =i; j < i+x; j++) pos[j] =Ap.size();
		Ap.push_back(make_pair(A[i],x));}
	int ans =0;
	vector<int> occ(1000000,0);
	for(int i =0; i < N; i++) occ[(A[i]+1000000000)%1000000]++;
	for(int k =0; k < N; k++) for(int k2 =0; k2 < N; k2++) if(k2 != k) {
		long long a =A[k], b =A[k2];
		if(a == b) {
			if(k != k2-1) continue;
			if(k > 0 && A[k-1] == A[k]) continue;}
		else {
			if(k > 0 && A[k] == A[k-1]) continue;
			if(k2 > 0 && A[k2] == A[k2-1]) continue;}
		int l =0, x =pos[k2];
		vector<int> sub;
		sub.push_back(pos[k]);
		sub.push_back(pos[k2]);
		Ap[pos[k]].ss--;
		Ap[pos[k2]].ss--;
		while(true) {
			int c =a+b;
			a =b;
			b =c;
			if(occ[(b%1000000+1000000000)%1000000] == 0) break;
			if(b >= a) {
				for(int i =10; i >= 0; i--) if(x+(1<<i) < Ap.size())
					if(Ap[x+(1<<i)].ff <= c) x +=1<<i;
				}
			else {
				for(int i =10; i >= 0; i--) if(x-(1<<i) >= 0)
					if(Ap[x-(1<<i)].ff >= c) x -=1<<i;
				}
			if(Ap[x].ff != c || Ap[x].ss == 0) break;
			sub.push_back(x);
			Ap[x].ss--;
			l++;}
		ALL_THE(sub,it) Ap[*it].ss++;
		ans =max(ans,l+2);}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing