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

bool check(string s) {
	for(int i =0; i < s.length(); i++) if(s[i] == '=')
		return (i-1 == s.length()-1-i);
	}

int main() {
	cin.sync_with_stdio(0);
	string s;
	cin >> s;
	if(check(s)) {cout << s << "\n"; return 0;}
	if(s[1] != '+') s.erase(s.begin());
	else s.erase(s.begin()+2);
	s +='|';
	if(check(s)) {cout << s << "\n"; return 0;}
	s.erase(--s.end());
	s.erase(--s.end());
	s.insert(0,"|");
	for(int i =0; i < s.length(); i++) if(s[i] == '=') {
		s.insert(i,"|");
		break;}
	if(check(s)) cout << s << "\n";
	else cout << "Impossible\n";
	return 0;}

// look at my code
// my code is amazing