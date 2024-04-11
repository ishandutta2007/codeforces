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
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define uint unsigned int
#define ff first
#define ss second
// mylittlepony
using namespace std;

int main() {
	int N;
	cin >> N;
	if(N%2 == 0) {
		cout << "-1\n";
		return 0;}
	for(int i =0; i < N; i++) {
		if(i > 0) cout << " ";
		cout << i;}
	cout << "\n";
	for(int i =0; i < N; i++) {
		if(i > 0) cout << " ";
		cout << i;}
	cout << "\n";
	for(int i =0; i < N; i++) {
		if(i > 0) cout << " ";
		cout << (2*i)%N;}
	cout << "\n";
    return 0;}
        
// look at my code
// my code is amazing