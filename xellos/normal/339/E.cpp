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

struct info {
	vector< pair<int,int> > sw; // aplikovane swapy
	vector<int> res;
	info() {}
	info(vector< pair<int,int> > a, vector<int> b) {sw =a, res =b;}};

int main() {
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> P(N);
	for(int i =0; i < N; i++) cin >> P[i];
	
	queue<info> q;
	info I; I.res =P;
	q.push(I);
	while(!q.empty()) {
		I =q.front();
		vector<int> chg0(1,0);
		for(int i =1; i < N; i++) if(abs(I.res[i]-I.res[i-1]) != 1) chg0.push_back(i);
		chg0.push_back(N);
		if(chg0.size() > 8-2*I.sw.size()) {q.pop(); continue;}
		vector<int> chg(1,0);
		for(int i =1; i < chg0.size(); i++) {
			if(chg0[i-1] == chg0[i]-2) chg.push_back(chg0[i]-1);
			chg.push_back(chg0[i]);}

		for(uint a =0; a < chg.size(); a++) for(uint b =a+1; b < chg.size(); b++) {
			if(chg[b] <= chg[a]+1) continue;
			vector<int> R =I.res;
			for(int i =0; i <= (chg[b]-chg[a]-1)/2; i++) swap(R[chg[a]+i],R[chg[b]-1-i]);
			bool B =true;
			for(int i =0; i < N; i++) if(R[i] != i+1) B =false;
			vector< pair<int,int> > swN =I.sw; swN.push_back(make_pair(chg[a],chg[b]));
			if(B) {
				cout << (int)swN.size() << "\n";
				for(int i =swN.size()-1; i >= 0; i--) cout << swN[i].ff+1 << " " << swN[i].ss << "\n";
				return 0;}
			if(I.sw.size() < 2) q.push(info(swN,R));}
		q.pop();}
    return 0;}
        
// look at my code
// my code is amazing