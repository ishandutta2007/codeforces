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
#define sent(x,y) (x >= 0 && y >= 0 && x < R && y < C)
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N,a;
	cin >> N;
	vector< vector< pair<int,int> > > V;
	vector< pair<int,int> > W;
	for(int i =0; i < N; i++) {
		cin >> a;
		if(a == 0) {
			V.push_back(W);
			W.clear();}
		else W.push_back(make_pair(a,i));}
	
	int M =V.size();
	vector<string> S(N,"");
	a =0;
	string str[] ={"pushStack","pushQueue","pushFront"};
	string strI[] ={"popStack","popQueue","popFront"};
	for(int i =0; i < M; i++) {
		int L =V[i].size();
		sort(V[i].begin(),V[i].end());
		for(int j =0; j < L-3; j++) S[V[i][j].ss] ="pushBack";
		for(int j =0; j < min(3,L); j++) S[V[i][L-1-j].ss] =str[j];
		a +=L+1;
		S[a-1] +='0'+min(3,L);}
	
	for(int i =a; i < N; i++) S[i] =str[0];
	for(int i =0; i < N; i++) {
		if(S[i][0] >= '0' && S[i][0] <= '3') {
			cout << S[i][0]-'0';
			for(int j =0; j < S[i][0]-'0'; j++) cout << " " << strI[j];
			cout << "\n";}
		else cout << S[i] << "\n";}
    return 0;}
        
// look at my code
// my code is amazing