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
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    vector<int> S(K,0);
    for(int i =0; i < N; i++) {
        cin >> A[i];
        S[i%K] +=A[i];}
    
    int ans =OVER9000;
    ALL_THE(S,it) ans =min(ans,*it);
    for(int i =0; i < K; i++) if(ans == S[i]) {
        cout << i+1 << "\n";
        return 0;}
    return 0;}
        
// look at my code
// my code is amazing