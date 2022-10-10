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
	int N,K;
	cin >> N >> K;
	for(int i =0; i <= K; i++) {
		if(i > 0) cout << " ";
		cout << K-i+1;}
	for(int i =K+1; i < N; i++) {
		if(i > 0) cout << " ";
		cout << i+1;}
	cout << endl;
	return 0;}

// look at my code
// my code is amazing