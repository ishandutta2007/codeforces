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
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
// mylittlepony
using namespace std;
    
int main() {
    int N,M;
    cin >> N >> M;
    int ans =0, a, b =1000;
    for(int i =0; i < N; i++) {
        cin >> a;
        b =min(a,b);
        ans =max(a,ans);}
    ans =max(ans,2*b);
    for(int i =0; i < M; i++) {
        cin >> a;
        if(a <= ans) {cout << "-1\n"; return 0;}}
    cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing