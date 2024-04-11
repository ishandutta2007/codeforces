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
	int N,M,K;
	cin >> N >> M >> K;
	if(N-1+M-1 < K) {cout << "-1\n"; return 0;}
	long long ans =max(1LL*(N/(K+1))*M,1LL*N*(M/(K+1)));
	for(int d =1; d*d <= N; d++) if(N%d == 0) {
		int i =d-1;
		if(i >= 0 && i <= K) ans =max(ans,1LL*(N/(i+1))*(M/(K-i+1)));
		i =N/d-1;
		if(i >= 0 && i <= K) ans =max(ans,1LL*(N/(i+1))*(M/(K-i+1)));}
	for(int d =1; d*d <= M; d++) if(M%d == 0) {
		int i =K-d+1;
		if(i >= 0 && i <= K) ans =max(ans,1LL*(N/(i+1))*(M/(K-i+1)));
		i =K-M/d+1;
		if(i >= 0 && i <= K) ans =max(ans,1LL*(N/(i+1))*(M/(K-i+1)));}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing