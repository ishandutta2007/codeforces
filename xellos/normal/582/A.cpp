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

int gcd(int x, int y) {
	if(x > y) swap(x,y);
	return (x == 0)?y:gcd(y%x,x);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	scanf(" %d",&N);
	vector<int> V(N*N);
	for(int i =0; i < N*N; i++) scanf(" %d",&V[i]);
	sort(begin(V),end(V));

	vector<int> A;
	multiset<int> rem;
	for(int i =N*N-1; i >= 0; i--) {
		if(!rem.empty() && *rem.rbegin() == V[i]) {
			rem.erase(--rem.end());
			continue;}
		ALL_THE(A,it) {
			int g =gcd(V[i],*it);
			rem.insert(g);
			rem.insert(g);}
		A.push_back(V[i]);}

	for(int i =0; i < N; i++) printf("%d ",A[i]);
	printf("\n");
	return 0;}

// look at my code
// my code is amazing