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
    int N,a;
    cin >> N;
    int poc[5] ={0,0,0,0,0};
    for(int i =0; i < N; i++) {
        cin >> a;
        poc[a]++;}

    int ans =N+1;
    for(int k =0; k <= poc[1]+poc[2]; k++) {
        // k: prazdnych 1+2
        if(2*poc[1]+poc[2] <= 3*k && 4*k <= 3*poc[1]+2*poc[2]+poc[3]) {
            // hladaj a,b: a+b=k, 0 <= a <= poc[1], 0 <= b=k-a <= poc[2], 2*k-a min.
            if(min(poc[1],k) >= max(0,k-poc[2]))
            ans =min(ans,2*k-min(poc[1],k));}
        if(2*poc[1]+poc[2] >= 3*k && 3*k >= 2*poc[1]+poc[2]-poc[4]) {
            // hladaj a,b: a+b=k, 0 <= a <= poc[1], 0 <= b=k-a <= poc[2], a+k max.
            if(min(poc[1],k) >= max(0,k-poc[2]))
            ans =min(ans,2*poc[1]+poc[2]-k-min(poc[1],k));}
        }
    int s =poc[1]+2*poc[2]+3*poc[3]+4*poc[4];
    if(s < 3 || s == 5) {cout << "-1\n"; return 0;}
    cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing