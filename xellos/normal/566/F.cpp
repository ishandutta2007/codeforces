// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	int N;
	scanf(" %d",&N);
	int mx =1000000;

	vector< vector<int> > div(mx+tisic);
	for(int i =0; i <= mx; i++) div[i].dibs(40);
	for(int i =11; i <= mx; i++) 
		for(int j =1; j <= mx/i; j++) div[i*j].push_back(i);

	vector<int> A(mx+tisic,0);
	for(int i =0; i < N; i++) {
		int a;
		scanf(" %d",&a);
		A[a]++;}

	vector<int> ans(mx+tisic,0);
	int ansF =0;
	for(int i =1; i <= mx; i++) if(A[i] > 0) {
		for(int j =1; j <= 10; j++) if(i%j == 0) ans[i] =max(ans[i],ans[j]);
		ALL_THE(div[i],it) ans[i] =max(ans[i],ans[*it]);
		ans[i] +=A[i];
		ansF =max(ansF,ans[i]);}

	printf("%d\n",ansF);
	return 0;}

// look at my code
// my code is amazing