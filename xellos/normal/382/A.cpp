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
	string s,t;
	cin >> s >> t;
	int a =0, b =0;
	bool B =false;
	for(int i =0; i < s.length(); i++) {
		if(s[i] == '|') B =true;
		else {
			if(B) b++;
			else a++;}}

	if((b+a+(int)t.length())%2 != 0) {cout << "Impossible\n"; return 0;}
	if(abs(b-a) > (int)t.length()) {cout << "Impossible\n"; return 0;}

	int x =0;
	while(b > a) {
		s.insert(0,t.substr(x,1));
		x++; a++;}
	while(b < a) {
		s +=t[x];
		b++; x++;}
	while(x < (int)t.length()) {
		s.insert(0,t.substr(x,1));
		x++;
		s +=t[x]; x++;}
	cout << s << "\n";
	return 0;}

// look at my code
// my code is amazing