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
	int N,K;
	scanf(" %d %d",&N,&K);
	int pm =0, mi =OVER9000, sum =0;
	for(int i =0; i < N; i++) {
		int a;
		scanf(" %d",&a);
		if(a >= 0) sum +=a;
		else {
			pm++;
			if(i < K) sum -=a;
			else sum +=a;}
		mi =min(mi,abs(a));}
	if(pm < K && (K-pm)%2 != 0) sum -=2*mi;
	printf("%d\n",sum);
	return 0;}

// look at my code
// my code is amazing