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
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-9
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define lng long long
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	cin >> N >> K;
	vector<int> A(2000+42);
	for(int i =0; i < N; i++) {
		int a;
		cin >> a;
		A[a-1]++;}
	int ans =0, a =2000;
	while(true) {
		while(a >= 0 && A[a] == 0) a--;
		if(a < 0) break;
		ans +=a;
		int k =K, b =a;
		while(b >= 0 && k > 0) {
			int x =min(A[b],k);
			k -=x;
			A[b] -=x;
			if(A[b] == 0) b--;}
		}
	cout << 2*ans << "\n";	
	return 0;}

// look at my code
// my code is amazing