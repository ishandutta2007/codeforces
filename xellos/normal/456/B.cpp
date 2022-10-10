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
	char c[300000];
	scanf(" %s",c);
	string s =(string)c;
	int N =s.length();
	int x =0;
	for(int i =max(0,N-2); i < N; i++) x =10*x+s[i]-'0';
	x %=4;
	int ans =1;
	for(int i =2; i <= 4; i++) {
		int a =1;
		for(int j =0; j < x; j++) a *=i;
		ans +=a;}
	printf("%d\n",ans%5);
	return 0;}

// look at my code
// my code is amazing