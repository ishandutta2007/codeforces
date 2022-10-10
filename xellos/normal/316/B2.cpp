// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;



int main() {
	int N,x;
	cin >> N >> x;
	vector<int> Next(N);
	vector<int> Prev(N,-1);
	queue<int> q;
    for(int i =0; i < N; i++) {
		cin >> Next[i];
		if(Next[i] > 0) Prev[Next[i]-1] =i;
		else q.push(i);}
	vector<int> suc;
	vector<int> path(N,-1);
	vector<int> dep(N,1);
	int p =0;
	int predB =0;
	
	while(!q.empty()) {
		int a =q.front();
		if(path[a] == -1) {path[a] =p; p++;}
		if(Prev[a] == -1 && path[a] != path[x-1]) suc.push_back(dep[a]);
		if(a == x-1) predB =dep[a];
		if(Prev[a] != -1) {
			path[Prev[a]] =path[a];
			dep[Prev[a]] =dep[a]+1;
			q.push(Prev[a]);}
		q.pop();}
	
	vector<bool> sums(N+tisic,false);
	sums[0] =true;
	for(int i =0; i < suc.size(); i++) for(int j =N-suc[i]; j >= 0; j--)
		if(sums[j]) sums[j+suc[i]] =true;
	for(int i =0; i <= N; i++) if(sums[i]) cout << i+predB << "\n";
	return 0;}
        
// look at my code
// my code is amazing