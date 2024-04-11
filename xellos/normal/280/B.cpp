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
	int N,a;
	cin >> N;
	vector< vector<int> > V(N);
	vector<int> S(N);
	for(int i =0; i < N; i++) {
		cin >> S[i];
		a =S[i];
		V[i].resize(31);
		for(int j =0; j < 31; j++) {
			V[i][j] =a%2;
			a /=2;}}
	a =30;
	while(true) {
		bool b =true;
		for(int i =0; i < N; i++) if(V[i][a] != V[0][a]) {
			b =false;
			break;}
		if(!b) break;
		a--;}
	
	int b =-1, c =-1, ans =0;
	for(int i =0; i < N; i++) {
		if(V[i][a] == 1) {
			b =S[i];
			c =-1;}
		else if(b >= 0 && S[i] > c) {
			ans =max(ans,S[i]^b);
			c =S[i];}}
	b =c =-1;
	for(int i =N-1; i >= 0; i--) {
		if(V[i][a] == 1) {
			b =S[i];
			c =-1;}
		else if(b >= 0 && S[i] > c) {
			ans =max(ans,S[i]^b);
			c =S[i];}}
	
	cout << ans << endl;
	return 0;}

// look at my code
// my code is amazing