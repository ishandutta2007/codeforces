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
#define soclose 1e-11
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int A,B;
	cin >> A >> B;
	int a[3] ={0,0,0};
	int b[3] ={0,0,0};
	while(A%2 == 0) {a[0]++; A /=2;}
	while(B%2 == 0) {b[0]++; B /=2;}
	while(A%3 == 0) {a[1]++; A /=3;}
	while(B%3 == 0) {b[1]++; B /=3;}
	while(A%5 == 0) {a[2]++; A /=5;}
	while(B%5 == 0) {b[2]++; B /=5;}
	if((A > 1 || B > 1) && (A != B)) cout << "-1\n";
	else cout << abs(a[0]-b[0])+abs(a[1]-b[1])+abs(a[2]-b[2]) << "\n";
	return 0;}

// look at my code
// my code is amazing