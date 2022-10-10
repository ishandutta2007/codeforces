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
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;
    
int main() {
    cin.sync_with_stdio(0);
    string s;
    cin >> s;
    vector< pair<char,int> > S;
    for(int i =0; i < s.length(); i++) {
        if(S.empty() || S.rbegin()->ff != s[i]) S.push_back(make_pair(s[i],0));
        S.rbegin()->ss++;}
    
    for(int i =0; i < S.size(); i++) {
        S[i].ss =min(S[i].ss,2);
        if(i > 0 && S[i-1].ss == 2) S[i].ss =1;
        for(int j =0; j < S[i].ss; j++) cout << (char)S[i].ff;}
    cout << "\n";
    return 0;}
        
// look at my code
// my code is amazing