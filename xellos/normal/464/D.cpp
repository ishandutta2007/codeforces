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
#define soclose 1e-6
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	cin >> N >> K;
	long double C =0;

	vector<long double> P(1000+tisic,0);
	P[1] =1;
	for(int i =1; i <= N; i++) {
		int t =270+max(0,int((i-20000)/80000.0*330));

		for(int j =1; j <= t; j++) 
			C +=P[j]*(j+1-2.0/(j+1));

		long double c =1.0/K;
		for(int j =t+patkan; j > 0; j--) 
			P[j] +=c*(P[j-1]/j-P[j]/(j+1));
		}

	cout << fixed << setprecision(10) << C/2.0+N/2.0 << "\n";
	return 0;}

// look at my code
// my code is amazing