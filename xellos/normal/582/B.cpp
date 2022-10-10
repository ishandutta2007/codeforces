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

struct fin {
	vector<int> T;
	fin(int N) {T.resize(N+tisic,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i =pos+1; i < (int)T.size(); i +=lastone(i)) T[i] =max(T[i],val);
		}

	int get(int pos) {
		int ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret =max(ret,T[i]);
		return ret;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,T, mx =300;
	scanf(" %d %d",&N,&T);
	vector<int> A(N);
	for(int i =0; i < N; i++) scanf(" %d",&A[i]);

	int rep1 =min(T,2*mx+tisic);
	int rep2 =max(0,min(2*mx+tisic,T-rep1));

	fin F1(mx);
	for(int i =0; i < rep1; i++) for(int j =0; j < N; j++) 
		F1.put(A[j],F1.get(A[j])+1);

	fin F2(mx);
	for(int i =0; i < rep2; i++) for(int j =N-1; j >= 0; j--)
		F2.put(mx-A[j],F2.get(mx-A[j])+1);

	int ans =0;
	for(int i =0; i <= mx; i++) {
		int poc =0;
		for(int j =0; j < N; j++) if(A[j] == i) poc++;
		ans =max(ans,F1.get(i)+F2.get(mx-i)+poc*(T-rep1-rep2));}

	printf("%d\n",ans);
	return 0;}

// look at my code
// my code is amazing