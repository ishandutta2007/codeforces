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
#define OVER9000 1234567890123456789LL
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

int s[3];

int main() {
	int N;
	cin >> N;
	for(int i =0; i < N; i++) {
		int a;
		cin >> a;
		s[i%3] +=a;}
	if(s[0] > s[1] && s[0] > s[2]) cout << "chest\n";
	if(s[1] > s[0] && s[1] > s[2]) cout << "biceps\n";
	if(s[2] > s[1] && s[2] > s[0]) cout << "back\n";
	return 0;}

// look at my code
// my code is amazing