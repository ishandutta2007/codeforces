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
	vector< pair<int,int> > E(M);
	vector< vector< pair<int,int> > > G(N);
	vector<long long> sum(N,0);
	for(int i =0; i < M; i++) {
		int a,b,c;
		scanf(" %d %d %d",&a,&b,&c);
		G[--a].push_back(make_pair(--b,c));
		G[b].push_back(make_pair(a,c));
		sum[a] +=c;
		sum[b] +=c;
		E[i] =make_pair(a,b);}

	vector<int> seq(N,0);
	int s =1;
	vector<bool> live(N,true);
	live[0] =false;
	vector<long long> sumIn(N,0);
	queue<int> q;
	ALL_THE(G[0],it) sumIn[it->ff] +=it->ss;
	for(int i =1; i < N-1; i++) if(sumIn[i]*2 == sum[i]) q.push(i);
	while(!q.empty()) {
		if(!live[q.front()] || 2*sumIn[q.front()] != sum[q.front()]) {q.pop(); continue;}
		live[q.front()] =false;
		seq[q.front()] =s++;
		ALL_THE(G[q.front()],it) if(it->ff < N-1 && live[it->ff]) {
			sumIn[it->ff] +=it->ss;
			if(2*sumIn[it->ff] == sum[it->ff]) q.push(it->ff);}
		q.pop();}
	seq[N-1] =N-1;

	for(int i =0; i < M; i++) {
		if(seq[E[i].ff] < seq[E[i].ss]) printf("0\n");
		else printf("1\n");}
	return 0;}

// look at my code
// my code is amazing