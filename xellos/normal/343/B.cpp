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
#define sent(x,y) (x >= 0 && y >= 0 && x < R && y < C)
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	string s;
	cin >> s;
	string t;
	for(int i =0; i < s.length(); i++) {
		t +=s[i];
		while(t.length() >= 2) {
			if(t[t.length()-1] != t[t.length()-2]) break;
			t.erase(t.end()-1);
			t.erase(t.end()-1);}}
	if(t.empty()) cout << "Yes\n";
	else cout << "No\n";
    return 0;}
        
// look at my code
// my code is amazing