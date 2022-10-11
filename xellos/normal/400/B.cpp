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
#define OVER9000 12345678901234567LL
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N,M;
	cin >> N >> M;
	string s;
	set<int> S;
	for(int i =0; i < N; i++) {
		int d =-1;
		cin >> s;
		for(int j =0; j < M; j++) {
			if(s[j] == 'G') {
				if(d != -1) {cout << "-1\n"; return 0;}
				d =j;}
			if(s[j] == 'S') {
				if(d == -1) {cout << "-1\n"; return 0;}
				S.insert(j-d);
				d =-1;}}
		if(d != -1) {cout << "-1\n"; return 0;}
		}
	cout << S.size() << "\n";
	return 0;}

// look at my code
// my code is amazing