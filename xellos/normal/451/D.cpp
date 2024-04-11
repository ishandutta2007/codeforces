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
#define OVER9000 1234567890123456780LL
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin >> S;
	int N =S.length();
	int p[] ={0,0,0,0};
	long long ans[] ={0,0};

	p[2*(S[0]-'a')]++;
	for(int i =1; i <= N; i++) {
		int k =S[i-1]-'a';
		// vsetky body za ktorymi je k
		ans[0] +=p[2*k+(i%2)];
		ans[1] +=p[2*k+1-(i%2)];
		if(i < N) p[2*(S[i]-'a')+(i%2)]++;}

	cout << ans[0] << " " << ans[1] << "\n";
	return 0;}

// look at my code
// my code is amazing