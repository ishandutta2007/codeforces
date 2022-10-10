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
#define sent(x,y) (x >= 0 && y >= 0 && x < R && y < C)
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N,a;
	cin >> N;
	int poc[] ={0,0,0,0,0,0,0,0};
	for(int i =0; i < N; i++) {
		cin >> a;
		poc[a]++;}
	if(poc[1] != N/3 || poc[5]+poc[7] > 0 || poc[6]+poc[4] != N/3) {
		cout << "-1\n";
		return 0;}
	if(poc[2]+poc[3] != N/3 || poc[2] < poc[4]) {cout << "-1\n"; return 0;}
	for(int i =0; i < N/3; i++) {
		cout << "1 ";
		if(i < poc[2]) cout << "2 ";
		else cout << "3 ";
		if(i < poc[4]) cout << "4\n";
		else cout << "6\n";}
    return 0;}
        
// look at my code
// my code is amazing