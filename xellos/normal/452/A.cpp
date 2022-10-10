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
	string ev[] ={"vaporeon","jolteon","flareon","espeon","umbreon","leafeon","glaceon","sylveon"};
	int N;
	string s;
	cin >> N >> s;
	for(int i =0; i < 8; i++) if(N == ev[i].length()) {
		bool ok =true;
		for(int j =0; j < N; j++) if(s[j] != '.' && s[j] != ev[i][j])
			ok =false;
		if(ok) {cout << ev[i] << "\n"; return 0;}
		}
	return 0;}

// look at my code
// my code is amazing