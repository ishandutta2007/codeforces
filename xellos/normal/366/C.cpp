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
    vector<int> A(N), B(N);
    for(int i =0; i < N; i++) cin >> A[i];
    for(int i =0; i < N; i++) {
        cin >> B[i];
        B[i] =K*B[i]-A[i];}

    // sum(B)=i, aka je maxsum(a)?
    vector<int> X(200000,-100000);
    X[50000] =0;
    for(int i =0; i < N; i++) {
        vector<int> Xn =X;
        for(int j =0; j < 200000; j++) if(j+B[i] < 200000 && X[j] >= 0 && j+B[i] >= 0)
            Xn[j+B[i]] =max(Xn[j+B[i]],A[i]+X[j]);
        X =Xn;}
    if(X[50000] == 0) cout << "-1\n";
    else cout << X[50000] << "\n";
    return 0;}
        
// look at my code
// my code is amazing