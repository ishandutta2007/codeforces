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
#define OVER9000 1234567890
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
// mylittledoge
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M,W;
	cin >> N >> M >> W;
	vector<long long> A(N);
	for(int i =0; i < N; i++) cin >> A[i];

	long long ansA =0, ansB =OVER9000;
	while(ansB-ansA > 1) {
		long long H =(ansB+ansA)/2;
		map<int,long long> down;
		long long D =0;
		long long m =0;
		for(int i =0; i < N; i++) {
			while(!down.empty() && down.begin()->ff <= i) {
				D -=down.begin()->ss;
				down.erase(down.begin());}
			long long a =A[i]+D;
			if(a >= H) continue;
			m +=H-a;
			down[i+W] +=H-a;
			D +=H-a;}
		if(1LL*M < m) ansB =H;
		else ansA =H;}

	cout << ansA << "\n";
	return 0;}

// look at my code
// my code is amazing