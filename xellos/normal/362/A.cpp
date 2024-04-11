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
#define soclose 1e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;
    
int main() {
    cin.sync_with_stdio(0);
    int T;
    cin >> T;
    for(int i =0; i < T; i++) {
        string s[8];
        for(int j =0; j < 8; j++) cin >> s[j];
        int k[2][2];
        int x =0;
        for(int j =0; j < 64; j++) if(s[j/8][j%8] == 'K') {
            k[x][0] =j/8, k[x][1] =j%8;
            x++;}
        int dx =k[0][0]-k[1][0], dy =k[0][1]-k[1][1];
        if(dx%4 == 0 && dy%4 == 0) cout << "YES\n";
        else cout << "NO\n";}
    return 0;}
        
// look at my code
// my code is amazing