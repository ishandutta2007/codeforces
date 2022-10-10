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
	int N;
	cin >> N;
	vector<string> V(N);
	bool r =false;
	for(int i =0; i < N; i++) {
		cin >> V[i];
		int x =0;
		for(int j =0; j < N; j++) if(V[i][j] != 'E') x++;
		if(x == 0) r =true;}
	
	if(!r) {
		for(int i =0; i < N; i++) for(int j =0; j < N; j++)
			if(V[i][j] != 'E') {
				cout << i+1 << " " << j+1 << "\n";
				break;}
		return 0;}
	
	for(int i =0; i < N; i++) {
		int x =0;
		for(int j =0; j < N; j++) if(V[j][i] != 'E') x++;
		if(x == 0) {cout << "-1\n"; return 0;}}

	for(int i =0; i < N; i++) for(int j =0; j < N; j++)
		if(V[j][i] != 'E') {
			cout << j+1 << " " << i+1 << "\n";
			break;}
    return 0;}
        
// look at my code
// my code is amazing