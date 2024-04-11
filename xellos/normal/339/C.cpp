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
	int M;
	cin >> s >> M;
	vector< vector < vector<int> > > ako(M+1, vector< vector<int> > (11, vector<int> (11,0))); 
	// pocet polozenych, rozdiel, posledna polozena
	for(int i =1; i <= 10; i++) if(s[i-1] == '1') ako[1][i][i] =-1;
	
	for(int i =1; i < M; i++) for(int j =1; j <= 10; j++) for(int k =1; k <= 10; k++) if(ako[i][j][k] != 0)
		for(int l =j+1; l <= 10; l++) if(l != k && s[l-1] == '1') ako[i+1][l-j][l] =k;
	
	stack<int> ans;
	int a =-1, b =-1;
	for(int i =1; i <= 10; i++) for(int j =1; j <= 10; j++) if(ako[M][i][j] != 0) a =i, b =j;
	if(a == -1) {cout << "NO\n"; return 0;}
	for(int i =M; i >= 1; i--) {
		ans.push(b);
		int c =b-a;
		b =ako[i][a][b];
		a =c;}
	cout << "YES\n";
	while(!ans.empty()) {
		cout << ans.top();
		ans.pop();
		cout << (ans.empty()?"\n":" ");}
    return 0;}
        
// look at my code
// my code is amazing