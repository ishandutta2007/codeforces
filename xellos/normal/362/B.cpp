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
    int N,M;
    cin >> N >> M;
    if(M == 0) {cout << "YES\n"; return 0;}
    vector<int> D(M);
    for(int i =0; i < M; i++) cin >> D[i];
    sort(D.begin(),D.end());
    if(D[0] == 1 || D[M-1] == N) {cout << "NO\n"; return 0;}
    for(int i =1; i < M-1; i++) if(D[i-1] == D[i]-1 && D[i+1] == D[i]+1) {
        cout << "NO\n";
        return 0;}
    cout << "YES\n";
    return 0;}
        
// look at my code
// my code is amazing