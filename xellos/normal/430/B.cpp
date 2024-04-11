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
	int N,K,x;
	cin >> N >> K >> x;
	vector<int> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	int ans =0;
	for(int i =0; i < N; i++) if(V[i] == x) {
		int a =i-1, b =i+1;
		while(a >= 0 && V[a] == x) a--;
		while(b < N && V[b] == x) b++;
		if(b-a+1 <= 3) continue;
		while(true) {
			if(a < 0 && b >= N) break;
			int c =(a >= 0)?V[a]:V[b], d =0, a0 =a, b0 =b;
			while(a >= 0 && V[a] == c) a--, d++;
			while(b < N && V[b] == c) b++, d++;
			if(d < 3) {
				a =a0, b =b0; 
				break;}
			}
		ans =max(ans,b-a-1);}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing