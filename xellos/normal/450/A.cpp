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
	int N,M;
	scanf(" %d %d",&N,&M);
	int mx =-1, ans =-1;
	for(int i =0; i < N; i++) {
		int a;
		scanf(" %d",&a);
		a =(a+M-1)/M;
		if(a >= mx) {
			mx =a;
			ans =i+1;}
		}
	printf("%d\n",ans);
	return 0;}

// look at my code
// my code is amazing