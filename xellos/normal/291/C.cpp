// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
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
	scanf(" %d %d",&N,&K);
	vector<uint> A(N);
	for(int i =0; i < N; i++) {
		uint a[4];
		scanf(" %d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
		A[i] =a[3]+256*(a[2]+256*(a[1]+256*a[0]));}
	
	vector<uint> mask(31,1);
	for(int i =0; i < 31; i++) mask[0] *=2;
	for(int i =1; i < 31; i++) {
		for(int j =0; j < 31-i; j++) mask[i] *=2; 
		mask[i] +=mask[i-1];}
	
	for(int i =0; i < 31; i++) {
		unordered_set<uint> s;
		for(int j =0; j < N; j++) s.insert(mask[i]&A[j]);
		if((int)s.size() == K) {
			uint a[4];
			a[3] =mask[i];
			for(int j =0; j < 3; j++) {
				a[2-j] =a[3-j]/256;
				a[3-j] %=256;}
			cout << a[0] << "." << a[1] << "." << a[2] << "." << a[3] << endl;
			return 0;}}
	
	printf("-1\n");
	return 0;}
        
// look at my code
// my code is amazing