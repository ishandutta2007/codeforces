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
	string s;
	cin >> s;
	int N =s.length(), ans =0;
	for(int i =0; i < N; i++) {
		for(int j =i; j <= N-4; j++) if(s[j] == 'b' && s[j+1] == 'e' && s[j+2] == 'a' && s[j+3] == 'r') {
			ans +=N-3-j;
			break;}
		}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing