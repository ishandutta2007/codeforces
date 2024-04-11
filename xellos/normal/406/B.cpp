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
#define OVER9000 1034567890
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
	vector<bool> F(1000000,true);
	for(int i =0; i < N; i++) {
		int x;
		cin >> x;
		F[x-1] =false;}
	int M =N;

	vector<int> ans;
	for(int i =0; i < 1000000; i++) if(F[i] && !F[1000000-1-i]) {
		ans.push_back(i);
		M--;
		F[i] =false;}

	M /=2;
	for(int i =0; i < 1000000; i++) if(F[i] && F[1000000-1-i] && M > 0) {
		F[i] =F[1000000-1-i] =false;
		M--;
		ans.push_back(i);
		ans.push_back(1000000-1-i);}

	cout << ans.size() << "\n";
	for(uint i =0; i < ans.size(); i++)
		cout << ans[i]+1 << ((i == ans.size()-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing