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
	vector<bool> isP(2000000+42,true);
	for(int i =2; i <= 2000000; i++) if(isP[i]) {
		cout << i;
		N--;
		if(N == 0) {cout << "\n"; return 0;}
		else cout << " ";
		for(int j =i; j <= 2000000/i; j++) isP[i*j] =false;}
    return 0;}
        
// look at my code
// my code is amazing