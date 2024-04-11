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
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector<string> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	string c1 ="RGBYW", c2 ="12345";

	int ans =10;
	for(int i =0; i < (1<<10); i++) {
		int akt =0;
		int j =i;
		while(j > 0) {akt +=j%2; j /=2;}
		map<string,string> M;
		bool ok =true;
		for(j =0; j < N; j++) {
			string s ="**";
			for(int k =0; k < 5; k++) if(V[j][0] == c1[k] && (i&(1<<k)) != 0) s[0] =V[j][0];
			for(int k =0; k < 5; k++) if(V[j][1] == c2[k] && (i&(1<<(5+k))) != 0) s[1] =V[j][1];
			if(M.find(s) == M.end()) M[s] =V[j];
			else if(M[s] != V[j]) ok =false;}
		if(ok) ans =min(ans,akt);}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing