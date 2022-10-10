// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 1034567890
#define patkan 9
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
using namespace std::tr1;

int main() {
	int N,M;
	cin >> N >> M;
	vector< vector<int> > V(N, vector<int>(M));
	vector<int> all(N*M);
	for(int i =0; i < N; i++) for(int j =0; j < M; j++) {
		cin >> V[i][j];
		all[i*M+j] =V[i][j];}
	sort(all.begin(),all.end());
	
	int ansA =0, ansB =N*M;
	while(ansB > ansA+1) {
		int ansC =(ansA+ansB)/2;
		vector< vector<int> > poc(M, vector<int> (M,0));
		bool b =false;
		for(int i =0; i < N; i++) {
			vector<int> W;
			for(int j =0; j < M; j++) if(all[ansC] <= V[i][j]) W.push_back(j);
			for(int j =0; j < (int)W.size(); j++) if(!b) for(int k =j+1; k < (int)W.size(); k++) {
				poc[W[j]][W[k]]++;
				if(poc[W[j]][W[k]] > 1) {b =true; break;}}
			if(b) break;}
		if(b) ansA =ansC;
		else ansB =ansC;}
	cout << all[ansA] << "\n";
	return 0;}
        
// look at my code
// my code is amazing