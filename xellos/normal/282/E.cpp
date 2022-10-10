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
	long long z =0, x =0,y;
	cin >> N;
	
	vector<long long> seq(N);
	for(int i =0; i < N; i++) {
		cin >> seq[i];
		z =(z^seq[i]);}
		
	vector<int> T[2];
	T[1].resize(43,-1);
	T[0].resize(43,-1);
	for(int i =0; i < 42; i++) T[0][i] =i+1;
	long long ans =z;
	
	for(int i =0; i < N; i++) {
		x =(x^seq[i]);
		int bit[42];
		y =x;
		for(int j =0; j < 42; j++) {
			bit[j] =y%2;
			y /=2;}
		a =0;
		for(int j =41; j >= 0; j--) {
			if(T[bit[j]][a] == -1) {
				T[bit[j]][a] =T[0].size();
				for(int k =0; k < 2; k++) T[k].push_back(-1);}
			a =T[bit[j]][a];}

		z =(z^seq[i]);
		y =z;
		for(int j =0; j < 42; j++) {
			bit[j] =y%2;
			y /=2;}
		a =0;
		long long akt =0;
		for(int j =41; j >= 0; j--) {
			akt *=2;
			if(T[1-bit[j]][a] == -1) a =T[bit[j]][a];
			else {
				a =T[1-bit[j]][a];
				akt++;}}
		ans =max(ans,akt);}
		
	cout << ans << endl;
	return 0;}

// look at my code
// my code is amazing