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
#define OVER9000 123456789012345678LL
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define uint unsigned int
#define ff first
#define ss second
#define abs(x) ((x < 0)?(-x):x)
#define exit() {printf("0\n"); return 0;}
#define mod 1000000007
// mylittlepony
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	sort(A.begin(),A.end());
	int a =0, b =0, c =0, ans =0;
	while(a < N || b > 0) {
		while(a < N) {
			if(A[a] > c) break;
			b++, a++;}
		if(a < N && b == 0) {
			ans +=A[a]-c;
			c =A[a];
			continue;}
		ans +=1-b%2;
		b /=2;
		c++;}
	cout << ans << endl;
	return 0;}
        
// look at my code
// my code is amazing