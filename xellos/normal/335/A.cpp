// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1034567890
#define patkan 9
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define ull unsigned long long
// mylittlepony
using namespace std;
using namespace std::tr1;
 
int main() {
	string s;
	int N;
	cin >> s >> N;
	vector<int> poc(26,0);
	for(int i =0; i < s.length(); i++) poc[s[i]-'a']++;
	
	int a =0, b =OVER9000;
	while(b-a > 1) {
		int c =(a+b)/2;
		int f =N;
		for(int i =0; i < 26; i++) f -=poc[i]/c+((poc[i]%c == 0)?0:1);
		if(f >= 0) b =c;
		else a =c;}
	if(b == OVER9000) {
		cout << "-1\n";
		return 0;}
	cout << b << "\n";
	for(int i =0; i < 26; i++) while(poc[i] > 0) {
		poc[i] -=b;
		N--;
		cout << (char)('a'+i);}
	for(int i =0; i < N; i++) cout << (char)('a');
	cout << "\n";
	return 0;}
        
// look at my code
// my code is amazing