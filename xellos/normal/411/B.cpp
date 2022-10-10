// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#define dibs reserve
#define OVER9000 12345678901234567LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N,M,K;
    cin >> N >> M >> K;
    vector<bool> A(N,false), B(K,false);
    vector<int> ans(N,0);
    vector< vector<int> > I(N,vector<int>(M));
    for(int i =0; i < N; i++) 
        for(int j =0; j < M; j++) cin >> I[i][j];
    for(int i =0; i < M; i++) {
        vector<int> W(K,0);
        for(int j =0; j < N; j++) {
            I[j][i]--;
            if(I[j][i] >= 0 && !A[j]) W[I[j][i]]++;}
        for(int j =0; j < K; j++) 
            if(W[j] > 1) B[j] =true;
        for(int j =0; j < N; j++) 
            if(I[j][i] >= 0 && B[I[j][i]]) {
                if(!A[j]) ans[j] =i+1;
                A[j] =true;}
        }
    for(int i =0; i < N; i++) cout << ans[i] << "\n";
    return 0;}
    
// look at my code
// my code is amazing