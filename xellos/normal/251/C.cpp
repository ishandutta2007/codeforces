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
	long long A,B;
	int K, mx =360360;
	scanf(" %I64d %I64d %d",&B,&A,&K);

	if(B-B%mx <= A) {
		vector<long long> ans(B-A+tisic,B-A+tisic);
		ans[0] =0;
		for(int i =1; i <= B-A; i++) {
			ans[i] =ans[i-1]+1;
			for(int k =2; k <= K; k++) if(i >= (i+A)%k)
				ans[i] =min(ans[i],ans[i-(i+A)%k]+1);
			}
		printf("%lld\n",ans[B-A]);
		return 0;}

	vector<int> pocDn(mx,mx+1),pocUp(mx,mx+1);
	pocDn[0] =pocUp[mx-1] =0;
	for(int i =1; i < mx; i++) {
		pocDn[i] =pocDn[i-1]+1;
		for(int k =2; k <= K; k++)
			pocDn[i] =min(pocDn[i],pocDn[i-i%k]+1);
		}
	for(int i =mx-1; i > 0; i--) {
		pocUp[i-1] =min(pocUp[i-1],pocUp[i]+1);
		for(int k =2; k <= K; k++)
			pocUp[i-i%k] =min(pocUp[i-i%k],pocUp[i]+1);
		}

	long long pmid =B/mx-A/mx-1;
	printf("%I64d\n",pmid*(1+pocDn[mx-1])+pocDn[B%mx]+1+pocUp[A%mx]);
	return 0;}

// look at my code
// my code is amazing