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
#define OVER9000 1234567890123456789LL
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
	int N,K,A;
	scanf(" %d %d %d",&N,&K,&A);
	map<int,int> M;
	M[0] =N-1;
	// poc*(A+1) <= N+1
	int poc =(N+1)/(A+1);
	if(poc < K) {printf("0\n"); return 0;}
	vector<bool> hit(N,false);

	int Q;
	scanf(" %d",&Q);
	for(int i =0; i < Q; i++) {
		int x;
		scanf(" %d",&x);
		x--;
		if(hit[x]) continue;
		hit[x] =true;
		auto it =M.upper_bound(x);
		it--;
		int l =it->ff, r =it->ss;
		M.erase(it);
		poc -=(r-l+2)/(A+1);
		poc +=(x-l+1)/(A+1);
		poc +=(r-x+1)/(A+1);
		if(r >= x+1) M[x+1] =r;
		if(x-1 >= l) M[l] =x-1;
		if(poc < K) {
			printf("%d\n",i+1);
			return 0;}
		}

	printf("-1\n");
	return 0;}

// look at my code
// my code is amazing