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
    int N, sa =0, sb =0,a,b;
    cin >> N;
    int rev =0;
    for(int i =0; i < N; i++) {
        cin >> a >> b;
        sa +=a, sb +=b;
        if((a-b)%2 != 0) rev++;}
    
    if((sb+sa)%2 != 0) cout << "-1\n";
    else {
        if(rev > 0) cout << (int)(sa%2 != 0) << "\n";
        else {if(sa%2 == 0) cout << "0\n"; else cout << "-1\n";}}
    return 0;}
        
// look at my code
// my code is amazing