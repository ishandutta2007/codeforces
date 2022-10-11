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
    string s; cin >> s;
    int N =s.length();
    
    vector<int> T(N+1,0);
    int g =(int)(s[N-1] == 'F'), lastM =N, ans =0;
    for(int i =N-2; i >= 0; i--) {
        if(s[i] == 'F') {g++; continue;}
        // collide directly
        if(s[i+1] == 'M') T[i] =T[i+1]+(int)(g > 0); 
        // dont collide
        else if(g > 0) {
            T[i] =g;
            if(lastM < N && T[i] <= T[lastM]) T[i] =T[lastM]+1;}
        ans =T[i];
        lastM =i;}
    cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing