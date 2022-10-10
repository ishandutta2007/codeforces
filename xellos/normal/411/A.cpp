// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#define dibs reserve
#define OVER9000 12345678901234567LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    if(s.length() < 5) {cout << "Too weak\n"; return 0;}
    int b =0;
    for(uint i =0; i < s.length(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') b |=1;
        if(s[i] >= 'A' && s[i] <= 'Z') b |=2;
        if(s[i] >= '0' && s[i] <= '9') b |=4;}
    cout << ((b == 7)?"Correct\n":"Too weak\n");
    return 0;}
    
// look at my code
// my code is amazing