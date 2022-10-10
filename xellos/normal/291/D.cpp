// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_set>
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
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;
using namespace std::tr1;

int main() {
	int N,K;
	cin >> N >> K;
	if(N == 1) {
		for(int i =0; i < K; i++) cout << N << endl;
		return 0;}
	map<int,int> aktN;
	aktN[1] =N-2;
	aktN[0] =N-1;
	vector<int> aktA(N,1);
	aktA[N-1] =0;
	
	for(int i =0; i < K; i++) {
		vector<int> newA =aktA;
		for(int j =0; j < N; j++) {
			auto it =aktN.upper_bound(N-1-j-aktA[j]);
			it--;
			if(j > 0) cout << " ";
			cout << it->second+1;
			newA[j] +=it->first;}
		cout << endl;
		aktN.clear();
		for(int j =0; j < N; j++) aktN[newA[j]] =j;
		aktA =newA;}
	return 0;}
        
// look at my code
// my code is amazing