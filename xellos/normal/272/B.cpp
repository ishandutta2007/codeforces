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
#define soclose 1e-8
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
	vector<int> P(50,0);
	for(int i =0; i < N; i++) {
		int a, p =0;
		scanf(" %d",&a);
		while(a > 0) {p +=a&1; a =a>>1;}
		P[p]++;}
	long long ans =0;
	for(int i =0; i < 50; i++) ans +=1LL*P[i]*(P[i]-1)/2;
	printf("%I64d\n",ans);
	return 0;}

// look at my code
// my code is amazing