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
	vector<int> D(N+1,OVER9000);
	D[N] =0;
	queue<int> q;
	q.push(N);
	
	while(!q.empty()) {
		int x =q.front(), y =q.front();
		while(y > 0) {
			if(D[x-y%10] > D[x]+1) {
				D[x-y%10] =D[x]+1;
				q.push(x-y%10);}
			y /=10;}
		if(x == 0) break;
		q.pop();}
	
	cout << D[0] << "\n";
    return 0;}
        
// look at my code
// my code is amazing