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
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-11
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	string s; cin >> s;
	long long B[3] ={0,0,0};
	for(int i =0; i < s.length(); i++) {
		if(s[i] == 'B') B[0]++;
		if(s[i] == 'S') B[1]++;
		if(s[i] == 'C') B[2]++;}
	long long A[3];
	for(int i =0; i < 3; i++) cin >> A[i];
	long long P[3];
	for(int i =0; i < 3; i++) cin >> P[i];
	long long R; cin >> R;

	long long ans =0;
	while(A[0]*B[0]+A[1]*B[1]+A[2]*B[2] > 0) {
		long long a =P[0]*max(0LL,B[0]-A[0])+P[1]*max(0LL,B[1]-A[1])+P[2]*max(0LL,B[2]-A[2]);
		if(a > R) break;
		R -=a;
		A[0] -=min(B[0],A[0]);
		A[1] -=min(B[1],A[1]);
		A[2] -=min(B[2],A[2]);
		ans++;}
	long long p =P[0]*B[0]+P[1]*B[1]+P[2]*B[2];
	cout << R/p+ans << "\n";
	return 0;}

// look at my code
// my code is amazing