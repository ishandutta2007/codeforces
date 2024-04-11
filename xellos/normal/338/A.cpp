// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 234567890
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

long long Pow(long long a, long long e, long long m) {
	if(e == 0) return 1;
	long long x =(e%2 == 0)?Pow(a,e/2,m):Pow(a,e-1,m);
	x =(e%2 == 0)?(x*x)%m:(x*a)%m;
	if(x < 0) x +=m;
	return x;}

int main() {
	int N,M,K;
	cin >> N >> M >> K;
	int xA =0, xB =M/K;
	// xK otazok spravne na zaciatku, potom bloky 0,(K-1)x1
	while(xB > xA+1) {
		int xC =(xB+xA)/2;
		bool b =true;
		if((M-xC*K)/(K-1)+(((M-xC*K)%(K-1) == 0)?0:1)-1 > N-M) b =false;
		if(b) xB =xC;
		else xA =xC;}
	if(M/(K-1)+((M%(K-1) == 0)?0:1)-1 <= N-M) xB =0;
	
	// xB-krat a =2a+2K
	// a == 2*(2**xB-1)
	long long mod =1000000009;
	long long a =(2*(Pow(2,xB,mod)-1)*K+M-xB*K)%mod;
	if(a < 0) a +=mod;
	cout << a << "\n";
    return 0;}
        
// look at my code
// my code is amazing