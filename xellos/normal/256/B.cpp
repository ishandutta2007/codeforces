// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	int N,x0,y0,C;
	scanf(" %d %d %d %d",&N,&x0,&y0,&C);
	int t0 =-1, t1 =1000000;
	while(t1-t0 > 1) {
		int t =(t1+t0)/2;
		long long p =0;
		for(int i =max(1,x0-t); i <= min(N,x0+t); i++) {
			int yl =y0-t+abs(i-x0), yr =y0+t-abs(i-x0);
			p +=max(0,min(yr,N)-max(yl,1)+1);}
		if(p >= C) t1 =t;
		else t0 =t;}
	printf("%d\n",t1);
	return 0;}

// look at my code
// my code is amazing