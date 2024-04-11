// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-9
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define lng long long
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for(int i =4; i <= N-4; i++) {
		bool b =true;
		for(int k =2; k*k <= i; k++) if(i%k == 0) b =false;
		if(b) continue;
		b =true;
		for(int k =2; k*k <= N-i; k++) if((N-i)%k == 0) b =false;
		if(!b) {cout << i << " " << N-i << "\n"; return 0;}}
	return 0;}

// look at my code
// my code is amazing