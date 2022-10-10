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
#define OVER9000 1234567890123456780LL
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittledoge
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int a =abs(x1-x2), b =abs(y1-y2);
	if(a != 0 && b != 0 && a != b) {
		cout << "-1\n";
		return 0;}
	if(a == 0) {
		cout << x1+b << " " << y1 << " " << x1+b << " " << y2 << "\n";
		return 0;}
	if(b == 0) {
		cout << x1 << " " << y1+a << " " << x2 << " " << y2+a << "\n";
		return 0;}
	if(x1 > x2) swap(x1,x2), swap(y1,y2);
	cout << x1 << " " << y2 << " " << x2 << " " << y1 << "\n";
	return 0;}

// look at my code
// my code is amazing