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
	int K[4];
	int N[3];
	int T[3];
	cin >> K[0];
	for(int i =0; i < 3; i++) cin >> N[i];
	for(int i =0; i < 3; i++) cin >> T[i];
	multiset<int> fin[4];
	for(int k =0; k < 1; k++)
		for(int i =0; i < K[k]; i++) fin[k].insert(0);

	int t =0;
	while(true) {
		while(!fin[3].empty() && *fin[3].begin() <= t)
			fin[3].erase(fin[3].begin());
		if(fin[0].size()+fin[1].size()+fin[2].size()+fin[3].size() == 0) break;
		for(int i =2; i >= 0; i--)
			while(!fin[i].empty() && *fin[i].begin() <= t && fin[i+1].size() < N[i]) {
//				cout << *fin[i].begin() << " "  << i << "\n";
				fin[i+1].insert(t+T[i]);
				fin[i].erase(fin[i].begin());}
		t++;}
	cout << t << "\n";
	return 0;}

// look at my code
// my code is amazing