// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;
using namespace std::tr1;

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	cin.sync_with_stdio(0);
	int N,M,a;
	cin >> N >> M;
	int ans =4;
	for(int i =0; i < N; i++) for(int j =0; j < M; j++) {
		cin >> a;
		if(a == 1 && (i == 0 || j == 0 || i == N-1 || j == M-1)) ans =2;}
	cout << ans << "\n"; 
	return 0;}
        
// look at my code
// my code is amazing