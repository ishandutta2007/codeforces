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
#include <cmath>
#include <algorithm>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
// mylittlepony
using namespace std;

int main() {
	int N;
	scanf(" %d",&N);
	vector<double> M(N);
	int x,y;
	for(int i =0; i < N; i++) {
		scanf(" %d %d",&x,&y);
		M[i] =atan2(y,x)*180/3.14159265358979;
		if(M[i] < 0) M[i] +=360;}
	sort(M.begin(),M.end());
	
	double ans =0;
	for(int i =0; i < N; i++) {
		double X =M[(i+1)%N];
		if(i == N-1) X +=360;
		ans =max(ans,X-M[i]);}
	printf("%.10f\n",360-ans);
	return 0;}

// look at my code
// my code is amazing