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
	vector< vector<int> > A(N,vector<int>(M,0));
	for(int i =0; i < N*M; i++) scanf(" %d",&A[i/M][i%M]);

	vector< vector<int> > G(M);
	int m =M;
	for(int i =0; i < N; i++) {
		vector< pair<int,int> > v(M);
		for(int j =0; j < M; j++) {
			v[j].ff =A[i][j];
			v[j].ss =j;}
		sort(begin(v),end(v));
		int a =0;
		for(int j =1; j < M; j++) if(v[j-1].ff != -1 && v[j-1].ff != v[j].ff) {
			while(a < j && v[j-1].ff != v[a].ff) a++;
			G.resize(m+1);
			for(int k =a; k < j; k++) G[v[k].ss].push_back(m);
			a =j;
			for(int k =j; k < M; k++) {
				if(v[k].ff != v[j].ff) break;
				G[m].push_back(v[k].ss);}
			m++;}
		}

	vector<int> D(m);
	for(int i =0; i < m; i++) ALL_THE(G[i],it) D[*it]++;
	queue<int> q;
	vector<int> seq;
	for(int i =0; i < m; i++) if(D[i] == 0) q.push(i);

	while(!q.empty()) {
		seq.push_back(q.front());
		ALL_THE(G[q.front()],it) {
			D[*it]--;
			if(D[*it] == 0) q.push(*it);}
		q.pop();}

	for(int i =0; i < m; i++) if(D[i] > 0) {
		printf("-1\n");
		return 0;}

	ALL_THE(seq,it) if(*it < M) printf("%d ",(*it)+1);
	printf("\n");
	return 0;}

// look at my code
// my code is amazing