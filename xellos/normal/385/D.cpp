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
	int N,L,R;
	cin >> N >> L >> R;
	R -=L;
	vector< pair<int,int> > P(N);
	vector<double> ang1(N);
	for(int i =0; i < N; i++) {
		cin >> P[i].ff >> P[i].ss >> ang1[i];
		P[i].ff -=L;
		P[i].ss =abs(P[i].ss);
		ang1[i] *=pi/180;}

	vector<double> ans(1<<N,0);
	for(int i =1; i < (1<<N); i++) for(int j =N-1; j >= 0; j--) if((i>>j)&1) {
		double d =ans[i^(1<<j)];
		double ang2 =atan2(P[j].ss,P[j].ff-d);
		double ang3 =pi-ang2-ang1[j];
		if(ang1[j] < soclose) cout << ".\n";
		double d2 =sqrt(P[j].ss*P[j].ss+(P[j].ff-d)*(P[j].ff-d));
		if(ang3 > soclose) ans[i] =max(ans[i],d+d2/sin(ang3)*sin(ang1[j]));
		else ans[i] =R+1;}

	cout << fixed << setprecision(10) << min(1.0*R,ans[(1<<N)-1]) << "\n";
	return 0;}

// look at my code
// my code is amazing