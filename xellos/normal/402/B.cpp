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
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456780LL
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	cin >> N >> K;
	vector<int> H(N);
	map<int,int> M;
	for(int i =0; i < N; i++) {
		cin >> H[i];
		H[i] -=K*i;
		M[H[i]]++;}
	int ans =N;
	ALL_THE(M,it) if(it->ff > 0) ans =min(ans,N-it->ss);
	cout << ans << "\n";
	ALL_THE(M,it) if(it->ff > 0 && ans == N-it->ss) {
		for(int i =0; i < N; i++) if(it->ff != H[i]) {
			int h =it->ff-H[i];
			if(h > 0) cout << "+ ";
			else {h *=-1; cout << "- ";}
			cout << i+1 << " " << h << "\n";}
		return 0;}
	return 0;}

// look at my code
// my code is amazing