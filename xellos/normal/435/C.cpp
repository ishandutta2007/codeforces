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
#define OVER9000 1034567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, S =0, St =0, mi =0, mx =0;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) {
		cin >> A[i];
		if(i%2 == 0) S +=A[i];
		else S -=A[i];
		St +=A[i];
		mi =min(mi,S);
		mx =max(mx,S);}

	vector< vector<char> > L(mx-mi,vector<char>(St,' '));
	int x =0, y =-mi;
	for(int i =0; i < N; i++) {
		for(int j =x; j < x+A[i]; j++) {
			if(i%2 == 0) L[y+j-x][j] ='/';
			else L[y-(j-x)][j] ='\\';}
		x +=A[i];
		if(i%2 == 0) y +=A[i]-1;
		else y -=A[i]-1;}

	for(int i =0; i < mx-mi; i++) {
		for(int j =0; j < St; j++) cout << L[(mx-mi)-1-i][j];
		cout << "\n";}
	return 0;}

// look at my code
// my code is amazing