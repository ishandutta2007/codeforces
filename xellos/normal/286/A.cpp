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
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define chocolate win
#define M 1000000007
// mylittlepony
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> V(N,-1);
	if(N%2 == 1) {
		V[N/2] =N/2+1;
		for(int i =1; i <= N/2; i++) {
			V[N/2-i] =N-i+1;
			V[N/2+i] =i;
			if(i%2 == 0) swap(V[N/2-i],V[N/2+i]);}
		}
	else for(int i =1; i <= N/2; i++) {
		V[N/2-i] =N-i+1;
		V[N/2+i-1] =i;
		if(i%2 == 0) swap(V[N/2-i],V[N/2+i-1]);}
	
	for(int i =0; i < N; i++) if(V[V[i]-1] != N-i) {
		cout << "-1\n";
		return 0;}
	for(int i =0; i < N; i++) {
		if(i > 0) cout << " ";
		cout << V[i];}
	cout << endl;
	return 0;}

// look at my code
// my code is amazing