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
	vector< pair<long long,long long> > P(N);
	for(int i =0; i < N; i++) scanf(" %I64d %I64d",&P[i].ff,&P[i].ss);
	vector< pair<long long, pair<int,int> > > D(N*(N-1)/2);
	int n =0;
	for(int i =0; i < N; i++) for(int j =i+1; j < N; j++)
		D[n++] =make_pair((P[i].ff-P[j].ff)*(P[i].ff-P[j].ff)+(P[i].ss-P[j].ss)*(P[i].ss-P[j].ss),make_pair(i,j));
	sort(begin(D),end(D));

	vector<int> V[100];
	for(int i =0; i < 100; i++) V[i].resize(N,0);
	for(int i =N*(N-1)/2-1; i >= 0; i--) {
		int a =D[i].ss.ff, b =D[i].ss.ss;
		int bits =0;
		for(int j =0; j < 100; j++) bits =bits|(V[j][a]&V[j][b]);
		if(bits > 0) {printf("%.10f\n",sqrt(D[i].ff)/2); return 0;}
		V[b/30][a] |=1<<(b%30);
		V[a/30][b] |=1<<(a%30);}
	return 0;}

// look at my code
// my code is amazing