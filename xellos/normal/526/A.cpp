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
#define dbl long double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	string S;
	cin >> N >> S;
	for(int l =1; l <= N; l++) for(int a =0; a < N; a++) {
		bool ok =true;
		for(int j =0; j < 5; j++) if(j*l+a >= N || S[j*l+a] == '.') ok =false;
		if(ok) {
			cout << "yes\n";
			return 0;}
		}
	cout << "no\n";
	return 0;}

// look at my code
// my code is amazing