// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456780LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.rbegin(); LIE != CAKE.rend(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	string let ="AHIMOTUVWXY";
	for(uint i =0; i < s.length(); i++) {
		bool b =false;
		for(int j =0; j < let.size(); j++) if(let[j] == s[i]) b =true;
		if(!b) {cout << "NO\n"; return 0;}}
	for(int i =0; i < s.length(); i++) if(s[s.length()-1-i] != s[i]) {
		cout << "NO\n";
		return 0;}
	cout << "YES\n";
	return 0;}

// look at my code
// my code is amazing