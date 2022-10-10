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
	int N,S,T;
	cin >> N >> S >> T;
	vector<int> V(N);
	for(int i =0; i < N; i++) {cin >> V[i]; V[i]--;}
	S--; T--;
	if(S == T) {printf("0\n"); return 0;}
	
	int akt =V[S], x =1;
	while(akt != S) {
		if(akt == T) {printf("%d\n",x); return 0;}
		akt =V[akt];
		x++;}
	printf("-1\n"); 
	return 0;}

// look at my code
// my code is amazing