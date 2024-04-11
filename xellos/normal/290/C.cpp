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
using namespace std::tr1;

int main() {
	int N,a,x =0, y =0, z =0, n =1;
	cin >> N;
	for(int i =0; i < N; i++) {
		cin >> a;
		x +=a;
		y++;
		if(max(x*n,y*z) == x*n) {
			z =x;
			n =y;}
		}
	printf("%.6f\n",(double)z/(double)n);
    return 0;}
        
// look at my code
// my code is amazing