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
	string s,t;
	cin >> s >> t;
	int jA =0, jB =0;
	ALL_THE(s,it) jA +=(int)(*it == '1');
	ALL_THE(t,it) jB +=(int)(*it == '1');
	if(jB > jA+jA%2) {cout << "NO\n"; return 0;}
	
	cout << "YES\n";
    return 0;}
        
// look at my code
// my code is amazing