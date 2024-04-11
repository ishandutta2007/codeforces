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
    int N;
    cin >> N;
    vector<int> V(N);
    for(int i =0; i < N; i++) cin >> V[i];
    string M;
    cin >> M;
    vector<int> S(N+1,0);
    for(int i =0; i < N; i++) S[i+1] =S[i]+V[i];
    
    int ans =0, a =0;
    for(int i =N-1; i >= 0; i--) if(M[i] == '1') {
        ans =max(ans,a+S[i]);
        a +=V[i];}
    ans =max(ans,a);
    cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing