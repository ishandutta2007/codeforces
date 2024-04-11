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
#define OVER9000 1234567890123456780LL
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	scanf(" %d",&N);
	vector<int> A(N);
	vector< pair<int,int> > ord(N);
	for(int i =0; i < N; i++) {
		scanf(" %d",&A[i]);
		ord[i].ff =A[i];
		ord[i].ss =i;}
	sort(begin(ord),end(ord));

	vector<int> nxt(N+1,-1),prev(N+1,-1);
	for(int i =0; i < N; i++) nxt[i] =i+1, prev[i+1] =i;
	int l =0, r =N-1;
	long long ans =0, sub =0;

	for(int i =0; i < N-2; i++) {
		if(ord[i].ss == l || ord[i].ss == r) {
			ans +=1LL*(ord[i].ff-sub)*(N-2-i);
			sub =ord[i].ff;
			if(ord[i].ss == l) l =nxt[l];
			else r =prev[r];
			continue;}
		int x =prev[ord[i].ss], y =nxt[ord[i].ss];
		ans +=min(A[x],A[y])-sub;
		prev[y] =x;
		nxt[x] =y;}

	printf("%lld\n",ans);
	return 0;}

// look at my code
// my code is amazing