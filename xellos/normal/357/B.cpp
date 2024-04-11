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
	int N,M;
	scanf(" %d %d",&N,&M);
	vector<int> ans(N,-1);
	for(int i =0; i < M; i++) {
		int a[3];
		scanf(" %d %d %d",&a[0],&a[1],&a[2]);
		bool fr[3] ={true,true,true};
		for(int j =0; j < 3; j++) {
			a[j]--;
			if(ans[a[j]] != -1) fr[ans[a[j]]] =false;}
		for(int j =0; j < 3; j++) if(ans[a[j]] == -1)
			for(int k =0; k < 3; k++) if(fr[k]) {
				ans[a[j]] =k;
				fr[k] =false;
				break;}
		}
	for(int i =0; i < N; i++) printf("%d ",ans[i]+1);
	printf("\n");
	return 0;}

// look at my code
// my code is amazing