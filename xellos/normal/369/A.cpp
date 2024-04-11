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
#include <cmath>
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
    int N,M,K,a;
    cin >> N >> M >> K;
    int b[] ={0,0};
    for(int i =0; i < N; i++) {
        cin >> a;
        b[a-1]++;}

    int x =min(b[0],M);
    M -=x; b[0] -=x;
    int y =min(b[1],M);
    M -=y; b[1] -=y;
    int z =min(b[1],K);
    K -=z; b[1] -=z;
    cout << b[0]+b[1] << "\n";
    return 0;}

// look at my code
// my code is amazing