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
#define dibs reserve
#define OVER9000 1234567890
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
	int N,a;
	cin >> N;
	map<int,int> M;
	for(int i =0; i < N; i++) {
		cin >> a;
		if(a > 0) M[a] =M[a]+1;}
	a =0;
	ALL_THE(M,it) {
		if(it->second > 2) {
			cout << "-1\n";
			return 0;}
		if(it->second == 2) a++;}
	cout << a << endl;
	return 0;}
        
// look at my code
// my code is amazing