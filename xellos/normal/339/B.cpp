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
	int N,M,a =0,b;
	cin >> N >> M;
	long long ans =0;
	for(int i =0; i < M; i++) {
		cin >> b;
		b--;
		if(b >= a) ans +=b-a;
		else ans +=N+b-a;
		a =b;}
	cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing