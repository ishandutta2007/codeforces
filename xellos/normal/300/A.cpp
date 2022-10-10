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
#define OVER9000 12345678901234567LL
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
using namespace std::tr1;

int main() {
	int N;
	cin >> N;
	vector<int> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	sort(V.begin(),V.end());
	for(int i =0; i < N; i++) if(V[i] == 0) {
		cout << 1 << " " << V[0] << endl;
		cout << N-3+i%2;
		for(int j =2-i%2; j < i; j++) cout << " " << V[j];
		for(int j =i+1; j < N; j++) cout << " " << V[j];
		cout << endl;
		if(i%2 == 0) cout << "2 0 " << V[1] << endl;
		else cout << "1 0\n";
		return 0;}
	return 0;}
        
// look at my code
// my code is amazing