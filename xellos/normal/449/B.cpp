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
	int N,M,K;
	cin >> N >> M >> K;
	vector< vector< pair<int,long long> > > G(N);
	for(int i =0; i < M; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		G[--a].push_back(make_pair(--b,c));
		G[b].push_back(make_pair(a,c));}
	vector<int> G2(N,-1);
	int ans =0;
	for(int i =0; i < K; i++) {
		int v,l;
		cin >> v >> l;
		v--;
		if(G2[v] >= 0) {
			ans++;
			G2[v] =min(G2[v],l);}
		else G2[v] =l;}

	priority_queue< pair<long long,int>, vector< pair<long long,int> > , greater< pair<long long,int> > > q;
	q.push(make_pair(0,0));
	vector<long long> D(N,OVER9000);
	D[0] =0;
	for(int i =1; i < N; i++) if(G2[i] >= 0) {
		q.push(make_pair(G2[i],i));
		D[i] =G2[i];}
	while(!q.empty()) {
		pair<long long,int> p =q.top();
		q.pop();
		if(D[p.ss] != p.ff) continue;
		ALL_THE(G[p.ss],it) if(D[it->ff] > p.ff+it->ss) {
			D[it->ff] =p.ff+it->ss;
			q.push(make_pair(D[it->ff],it->ff));}
		}

	for(int i =1; i < N; i++) if(G2[i] != -1) {
		bool rem =false;
		ALL_THE(G[i],it) if(D[i] == it->ss+D[it->ff]) rem =true;
		if(rem) ans++;}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing