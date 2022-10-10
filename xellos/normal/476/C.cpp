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
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	// x == z(1+kb)
	long long mod =1000000007, a,b, s1 =0, s2 =0;
	cin >> a >> b;
	for(int i =1; i < b; i++) s1 +=i;
	for(int i =1; i <= a; i++) s2 +=1+(1LL*i*b)%mod;
	s1 -=mod*(s1/mod);
	s2 -=mod*(s2/mod);
	cout << (s1*s2)%mod << "\n";
	return 0;}

// look at my code
// my code is amazing