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
	cin.sync_with_stdio(0);
	string s;
	cin >> s;

	for(int i =0; i < s.length(); i++) if(s[i] == '1') {
		s.erase(s.begin()+i);
		break;}
	for(int i =0; i < s.length(); i++) if(s[i] == '6') {
		s.erase(s.begin()+i);
		break;}
	for(int i =0; i < s.length(); i++) if(s[i] == '8') {
		s.erase(s.begin()+i);
		break;}
	for(int i =0; i < s.length(); i++) if(s[i] == '9') {
		s.erase(s.begin()+i);
		break;}

	int b =0;
	for(int i =0; i < s.length(); i++) {
		if(s[i] != '0') break;
		b++;}
	s =s.substr(b,s.length()-b);

	int a =0;
	for(int i =0; i < s.length(); i++) a =(10*a+s[i]-'0')%7;
	a =(a*10000)%7;

	string rem[] ={"9618","6819","1689","6891","1698","9168","1896","9618"};
	s +=rem[7-a];

	for(int i =0; i < b; i++) s +="0";
	cout << s << "\n";
	return 0;}

// look at my code
// my code is amazing