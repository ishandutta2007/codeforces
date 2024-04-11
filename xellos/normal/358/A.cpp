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
	vector<int> X(N);
	for(int i =0; i < N; i++) cin >> X[i];
	
	for(int i =0; i < N-1; i++) for(int j =0; j < N-1; j++) {
		int a =min(X[i],X[i+1]), b =max(X[i],X[i+1]);
		int c =min(X[j],X[j+1]), d =max(X[j],X[j+1]);
		if(a < c && b > c && b < d) {
			cout << "yes\n";
			return 0;}}
	cout << "no\n";
    return 0;}
        
// look at my code
// my code is amazing