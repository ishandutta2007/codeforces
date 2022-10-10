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
	string s;
	cin >> s;
	int N =s.length(),M;
	vector<int> V(N-1);
	for(int i =0; i < N-1; i++) V[i] =(int)(s[i] == s[i+1]);
	vector<int> S(N,0);
	for(int i =1; i < N; i++) S[i] =S[i-1]+V[i-1];
	
	cin >> M;
	for(int i =0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		cout << S[b-1]-S[a-1] << "\n";}
    return 0;}
        
// look at my code
// my code is amazing