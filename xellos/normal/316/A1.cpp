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
	int ans =1;
	int numL =0, firstL =(int)(s[0] >= 'A' && s[0] <= 'Z');
	vector<bool> je(10,false);
	for(int i =0; i < s.length(); i++) if(s[i] >= 'A' && s[i] <= 'Z') je[s[i]-'A'] =true;
	for(int i =0; i < 10; i++) numL +=(int)je[i];
	
	if(firstL == 0) for(int i =0; i < numL; i++) ans *=10-i;
	else {
		int ans0 =1;
		for(int i =0; i < numL-1; i++) ans0 *=9-i;
		for(int i =0; i < numL; i++) ans *=10-i;
		ans -=ans0;}
	if(s[0] == '?') ans *=9;
	cout << ans;
	
	for(int i =1; i < s.length(); i++) if(s[i] == '?') cout << "0";
	cout << "\n";
    return 0;}
        
// look at my code
// my code is amazing