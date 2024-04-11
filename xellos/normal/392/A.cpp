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
#define OVER9000 12345678901234567LL
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
	int N, ans, y =-1;
	cin >> N;
	if(N == 0) {cout << "1\n"; return 0;}
	ans =N;
	long long j =N;
	for(int i =0; i <= N; i++) {
		while(1LL*N*N < j*j+1LL*i*i) j--;
		if(j == y) ans++;
		y =j;}
	cout << ans*4 << "\n";
	return 0;}

// look at my code
// my code is amazing