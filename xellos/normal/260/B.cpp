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
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
// mylittlepony
using namespace std;

int main() {
	map<string,int> M;
	
	string s;
	cin >> s;
	int cif[8] ={0,1,3,4,6,7,8,9};
	int d[12] ={31,28,31,30,31,30,31,31,30,31,30,31};
	for(int i =0; i < s.length()-9; i++) {
		bool B =true;
		for(int j =0; j < 8; j++) if(s[i+cif[j]] < '0' || s[i+cif[j]] > '9') {
			B =false;
			break;}
		if(s[i+2] != '-' || s[i+5] != '-') B =false;
		if(!B) continue;
		int a =(s[i]-'0')*10+(s[i+1]-'0'), b =(s[i+3]-'0')*10+(s[i+4]-'0'), c =(s[i+6]-'0')*1000+(s[i+7]-'0')*100+(s[i+8]-'0')*10+(s[i+9]-'0');
		if(c > 2015 || c < 2013) B =false;
		if(b == 0 || b > 12) B =false;
		if(a == 0 || a > d[b-1]) B =false;
		if(B) {
			string t =s.substr(i,10);
			M[t] =M[t]+1;}}
	int x =0;
	for(auto it =M.begin(); it != M.end(); it++) x =max(x,it->second);
	for(auto it =M.begin(); it != M.end(); it++) if(x == it->second) {
		cout << it->first << endl;
		return 0;}
	return 0;}

// look at my code
// my code is amazing