#include <bits/stdc++.h>
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
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265359
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	vector<string> ans;
	reverse(begin(s),end(s));
	while(!s.empty()) {
		string sn =s;
		for(int i =0; i < s.length(); i++) if(sn[i] != '0') {
			sn[i] ='1';
			s[i]--;}
		ans.push_back(sn);
		while(s.size() > 0 && s[s.length()-1] == '0') s.erase(s.end()-1);}
	cout << ans.size() << "\n";
	ALL_THE(ans,it) {
		s =*it;
		reverse(begin(s),end(s));
		cout << s << " ";}
	cout << "\n";
	return 0;}

// look at my code
// my code is amazing