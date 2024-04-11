// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1034567890
#define patkan 9
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
using namespace std::tr1;

int main() {
	long long xa =OVER9000, xb =0;
	long long ya =xa, yb =xb;
	long long a,b,c,d, S =0;
	int N;
	cin >> N;
	for(int i =0; i < N; i++) {
		cin >> a >> c >> b >> d;
		S +=(b-a)*(d-c);
		xa =min(xa,a);
		xb =max(xb,b);
		ya =min(ya,c);
		yb =max(yb,d);}
	if((xb-xa)*(yb-ya) == S && xb-xa == yb-ya) cout << "YES\n";
	else cout << "NO\n";
	return 0;}
        
// look at my code
// my code is amazing