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
    string s;
    cin >> s;
    int N =s.length();
    
    vector<int> S[3];
    for(int i =0; i < 3; i++) {
        S[i].resize(N+1,0);
        for(int j =0; j < N; j++) S[i][j+1] =S[i][j]+(int)(s[j] == 'x'+i);
        }
    
    int M,a,b; 
    cin >> M;
    for(int i =0; i < M; i++) {
        cin >> a >> b;
        if(b-a < 2) {cout << "YES\n"; continue;}
        int p[3];
        for(int j =0; j < 3; j++) p[j] =S[j][b]-S[j][a-1];
        bool ans =true;
        for(int j =0; j < 3; j++) if(abs(p[j]-p[(j+1)%3]) > 1) ans =false;
        if(!ans) cout << "NO\n";
        else cout << "YES\n";}
    return 0;}
        
// look at my code
// my code is amazing