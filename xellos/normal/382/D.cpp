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
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N,M;
	cin >> N >> M;
	vector<int> G(N*M,-1);
	vector<string> V(N);
	for(int i =0; i < N; i++) {
		cin >> V[i];
		for(int j =0; j < M; j++) {
			if(V[i][j] == '<') G[i*M+j] =i*M+j-1;
			if(V[i][j] == '>') G[i*M+j] =i*M+j+1;
			if(V[i][j] == '^') G[i*M+j] =i*M+j-M;
			if(V[i][j] == 'v') G[i*M+j] =i*M+j+M;}
		}

	vector< vector<int> > Gi(N*M);
	for(int i =0; i < N*M; i++) if(G[i] >= 0) Gi[G[i]].push_back(i);

	vector<int> dep(N*M,-1);
	vector<int> ex(N*M,-1);
	queue<int> q;
	for(int i =0; i < N; i++) for(int j =0; j < M; j++) if(V[i][j] == '#') {
		int x =M*i+j;
		q.push(x);
		ex[x] =x; dep[x] =0;
		while(!q.empty()) {
			ALL_THE(Gi[q.front()],it) if(ex[*it] == -1) {
				if(q.front() == x) ex[*it] =*it;
				else ex[*it] =ex[q.front()];
				dep[*it] =dep[q.front()]+1;
				q.push(*it);}
			q.pop();}
		}

	for(int i =0; i < N*M; i++) if(ex[i] == -1) {
		cout << "-1\n";
		return 0;}

	int a =0, b =0;
	ALL_THE(dep,it) a =max(a,*it);
	ALL_THE(dep,it) if(*it < a) b =max(b,*it);
	for(int i =0; i < N*M; i++) if(dep[i] == a) {
		for(int j =0; j < N*M; j++) if(dep[j] == a && ex[j] != ex[i]) b =a;
		break;}
	cout << a+b << "\n";
	return 0;}

// look at my code
// my code is amazing