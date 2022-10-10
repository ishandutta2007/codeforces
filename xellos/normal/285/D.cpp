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
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define chocolate win
#define M 1000000007
// mylittlepony
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> V(N);
	for(int i =0; i < N; i++) V[i] =i;
	
	if(N%2 == 0) {printf("0\n"); return 0;}
	long long x[16] ={1,3,15,133,2025,37851,1030367,36362925,1606008513};
	long long ans =x[N/2];
	for(int i =2; i <= N; i++) {
		ans =(ans*i)%M;
		if(ans < 0) ans +=M;}
	cout << ans << endl;
	return 0;}

// look at my code
// my code is amazing