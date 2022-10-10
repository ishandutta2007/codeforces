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
#include <iomanip>
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

int main() {
	int M,R;
	cin >> M >> R;
	double x =2*M;
	for(int i =1; i < M; i++) {
		if(M-i == 1) x +=2*i*(2*(M-i)+sqrt(2));
		else x +=2*i*(2*(M-i-1)+2*sqrt(2));}
	cout << fixed << setprecision(10) << x*R/M/M << "\n";
    return 0;}
        
// look at my code
// my code is amazing