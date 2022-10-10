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
    int N,M,K,S,a,b;
    cin >> N >> M >> K >> S;
    
    int A[4][9];
    for(int i =0; i < 9; i++) {
        A[0][i] =A[2][i] =-1000000;
        A[1][i] =A[3][i] =1000000;}
    for(int i =0; i < N; i++) for(int j =0; j < M; j++) {
        cin >> a;
        A[0][a-1] =max(A[0][a-1],i+j);
        A[1][a-1] =min(A[1][a-1],i+j);
        A[2][a-1] =max(A[2][a-1],i-j);
        A[3][a-1] =min(A[3][a-1],i-j);}
        
    int ans =0;
    cin >> a; a--;
    for(int i =1; i < S; i++) {
        cin >> b; b--;
        ans =max(ans,A[0][a]-A[1][b]);
        ans =max(ans,A[0][b]-A[1][a]);
        ans =max(ans,A[2][a]-A[3][b]);
        ans =max(ans,A[2][b]-A[3][a]);
        a =b;}
    cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing