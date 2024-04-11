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
#define soclose 1e-9
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittledoge
using namespace std;
    
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin >> N >> K;
    if(N < 2) {
        if(K == 0) cout << "1\n";
        else cout << "-1\n";
        return 0;}
    int x =N/2-1;
    if(K-x <= 0) {cout <<"-1\n"; return 0;}
    cout << K-x << " " << 2*(K-x) << " ";
    for(int i =2; i < N; i++) cout << 2*(K-x)+i << ((i == N-1)?"\n":" ");
    return 0;}
        
// look at my code
// my code is amazing