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
// mylittlepony
using namespace std;

int main() {
	int N;
	cin >> N;
	string pl[] ={"BitLGM\n","BitAryo\n"};
	int A[5];
	for(int i =0; i < N; i++) cin >> A[i];

	if(N == 1) {
		if(A[0] > 0) cout << pl[0];
		else cout << pl[1];
		return 0;}
		
	if(N == 2) {
		vector< vector<bool> > V(301);
		for(int i =0; i <= 300; i++) V[i].resize(301,false);
		for(int i =0; i <= 300; i++) for(int j =0; j <= 300; j++) {
			for(int k =1; k <= min(i,j); k++) if(!V[i-k][j-k]) {
				V[i][j] =true; 
				break;}
			if(!V[i][j]) for(int k =1; k <= i; k++) if(!V[i-k][j]) {
				V[i][j] =true;
				break;}
			if(!V[i][j]) for(int k =1; k <= j; k++) if(!V[i][j-k]) {
				V[i][j] =true; 
				break;}
			}
		cout << pl[1-(int)(V[A[0]][A[1]])];
		return 0;}
		
	cout << pl[(int)((A[0]^A[1]^A[2]) == 0)];
	return 0;}

// look at my code
// my code is amazing