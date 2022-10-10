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
#define dibs reserve
#define OVER9000 1234567890
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
	getline(cin,s);
	vector<string> V;
	string akt;
	bool open =false;
	for(uint i =0; i < s.length(); i++) {
		if(s[i] == '"') {
			if(open || akt.length() > 0) {
				V.push_back(akt);
				akt.clear();}
			open =!open;}
		else if(open) akt +=s[i];
		else if(s[i] != ' ') akt +=s[i];
		else if(akt.length() > 0) {
			V.push_back(akt);
			akt.clear();}}
	if(akt.length() > 0) V.push_back(akt);
			
	for(uint i =0; i < V.size(); i++) cout << "<" << V[i] << ">\n";
	return 0;}
        
// look at my code
// my code is amazing