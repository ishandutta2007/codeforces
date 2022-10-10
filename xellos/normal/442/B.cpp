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
	int N;
	cin >> N;
	vector<double> V(N);
	double ans =0, p =0, p0 =1;
	for(int i =0; i < N; i++) cin >> V[i];
	sort(V.begin(),V.end());
	cout << fixed << setprecision(12);
	if(V[N-1] > 1-soclose) {
		cout << 1.0 << "\n";
		return 0;}

	for(int i =N-1; i >= 0; i--) {
		p +=V[i]/(1-V[i]);
		p0 *=(1-V[i]);
		ans =max(ans,p0*p);}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing