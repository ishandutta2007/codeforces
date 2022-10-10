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
#define OVER9000 2234567890123456780LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.rbegin(); LIE != CAKE.rend(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	string s;
	cin >> N >> K >> s;
	if(N == 1) {cout << "PRINT " << s << "\n"; return 0;}
	K--;
	if(K < N-1-K) {
		for(int i =K; i >= 0; i--) {
			cout << "PRINT " << s[i] << "\n";
			if(i > 0) cout << "LEFT\n";}
		for(int i =0; i <= K; i++) cout << "RIGHT\n";
		for(int i =K+1; i < N; i++) {
			cout << "PRINT " << s[i] << "\n";
			if(i < N-1) cout << "RIGHT\n";}
		}
	else {
		for(int i =K; i < N; i++) {
			cout << "PRINT " << s[i] << "\n";
			if(i < N-1) cout << "RIGHT\n";}
		for(int i =N-1; i >= K; i--) cout << "LEFT\n";
		for(int i =K-1; i >= 0; i--) {
			cout << "PRINT " << s[i] << "\n";
			if(i > 0) cout << "LEFT\n";}
		}
	return 0;}

// look at my code
// my code is amazing