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
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i =0; i < N; i++) cin >> P[i];

    vector< vector<int> > costG(N, vector<int>(N));
    for(int i =0; i < N; i++) {
        int x =0;
        for(int j =i+1; j < N; j++) {
            costG[i][j] =x;
            if(P[j] > P[i]) x++;}
        x =0;
        for(int j =i-1; j >= 0; j--) {
            costG[i][j] =x;
            if(P[j] > P[i]) x++;}}

    vector< vector<int> > costL(N, vector<int>(N));
    for(int i =N-1; i >= 0; i--) {
        int x =0;
        for(int j =i-1; j >= 0; j--) {
            costL[i][j] =x;
            if(P[j] < P[i]) x++;}
        x =0;
        for(int j =i+1; j < N; j++) {
            costL[i][j] =x;
            if(P[j] < P[i]) x++;}}
    
    int S =0;
    for(int i =0; i < N; i++) for(int j =i+1; j < N; j++)
        if(P[i] > P[j]) S++;
        
    int ansA =S, ansB =0;
    for(int i =0; i < N; i++) for(int j =i+1; j < N; j++)
        ansA =min(ansA,S-2*(int)(P[i] > P[j])+1-costL[i][j]-costG[j][i]+costL[j][i]+costG[i][j]);
    
    for(int i =0; i < N; i++) for(int j =i+1; j < N; j++)
        if(ansA == S-2*(int)(P[i] > P[j])+1-costL[i][j]-costG[j][i]+costL[j][i]+costG[i][j]) ansB++;
    
    cout << ansA << " " << ansB << "\n";
    return 0;}
        
// look at my code
// my code is amazing