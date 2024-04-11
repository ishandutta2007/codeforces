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
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	sort(V.begin(),V.end());
	int a =N;
	long long ans =0;
	while(a > 0) {
		for(int i =0; i < a; i++) ans +=V[N-1-i];
		a /=4;}
	cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing