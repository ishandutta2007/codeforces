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
	int N,M,K,a;
	cin >> N >> M >> K;
	map<int,int> A;
	map<int,int> B;
	for(int i =0; i < N; i++) {
		cin >> a;
		A[a] =A[a]+1;}
	for(int i =0; i < M; i++) {
		cin >> a;
		B[a] =B[a]+1;
		if(A.find(a) == A.end()) A[a] =0;}
	
	vector<int> V;
	ALL_THE(A,it) V.push_back(it->ss-B[it->ff]);
	for(int i =V.size()-1; i >= 0; i--) {
		if(V[i] > 0) {cout << "YES\n"; return 0;}
		if(i > 0) V[i-1] +=V[i];}
	cout << "NO\n";
    return 0;}
        
// look at my code
// my code is amazing