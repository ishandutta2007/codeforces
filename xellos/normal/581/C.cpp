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
	int N,K;
	scanf(" %d %d",&N,&K);
	vector<int> A(20,0);
	int ans =0, p =0;
	for(int i =0; i < N; i++) {
		int a;
		scanf(" %d",&a);
		ans +=a/10;
		if(a < 100) {
			A[10-a%10]++;
			p +=10-(a+10-a%10)/10;}
		}
	A[10] +=p;
	for(int i =1; i <= 10; i++) {
		int k =min(K/i,A[i]);
		K -=i*k;
		ans +=k;}
	printf("%d\n",ans);
	return 0;}

// look at my code
// my code is amazing