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
using namespace std::tr1;

int main() {
	string s;
	int N;
	cin >> s;
	for(uint i =0; i < s.length(); i++) if(s[i] >= 'A' && s[i] <= 'Z')
		s[i] =(s[i]-'A')+'a';
	cin >> N;
	for(uint i =0; i < s.length(); i++) if(s[i]-'a' < N) 
		s[i] =(s[i]-'a')+'A';
	cout << s << endl;
    return 0;}
        
// look at my code
// my code is amazing