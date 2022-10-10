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
	int N;
	cin >> N;
	vector<int> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	int ans =0;
	for(int i =0; i < N; i++) for(int j =i; j < N; j++) {
		int akt =0;
		for(int k =0; k < N; k++) {
			if(k < i || k > j) akt +=V[k];
			else akt +=1-V[k];}
		ans =max(ans,akt);}
	cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing