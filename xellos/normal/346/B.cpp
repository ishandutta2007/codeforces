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
    string s,t,vir;
    cin >> s >> t >> vir;
    int N =s.length(), M =t.length(), V =vir.length();
    
    vector<int> prev(V+1,0);
    for(int i =2; i <= V; i++) {
        prev[i] =prev[i-1];
        while(prev[i] > 0 && vir[prev[i]] != vir[i-1]) prev[i] =prev[prev[i]];
        if(vir[prev[i]] == vir[i-1]) prev[i]++;}

    vector< vector<int> > next(V+1,vector<int>(26,0));
    for(int i =0; i < V; i++) for(int j =0; j < 26; j++) {
        next[i][j] =i;
        while(next[i][j] > 0 && vir[next[i][j]] != 'A'+j) next[i][j] =prev[next[i][j]];
        if(vir[next[i][j]] == 'A'+j) next[i][j]++;}

    vector< vector< vector<int> > > A(N+1, vector< vector<int> >(M+1, vector<int>(V+1,0)));
    vector< vector< vector<int> > > ako(N+1, vector< vector<int> >(M+1, vector<int>(V+1,0)));
    for(int i =0; i <= N; i++) for(int j =0; j <= M; j++) if(i+j < N+M)
        for(int k =0; k < V; k++) {
            if(i < N && j < M && s[i] == t[j]) 
                if(A[i+1][j+1][next[k][s[i]-'A']] <= A[i][j][k]+1) {
                    A[i+1][j+1][next[k][s[i]-'A']] =A[i][j][k]+1;
                    ako[i+1][j+1][next[k][s[i]-'A']] =200*200*i+200*j+k;}
                    
            if(i < N) if(A[i+1][j][k] <= A[i][j][k]) {
                A[i+1][j][k] =A[i][j][k];
                ako[i+1][j][k] =ako[i][j][k];}
            if(j < M) if(A[i][j+1][k] <= A[i][j][k]) {
                A[i][j+1][k] =A[i][j][k];
                ako[i][j+1][k] =ako[i][j][k];}
            }
        
    int ans =0, x =N, y =M, z =0;
    for(int i =0; i < V; i++) {
        ans =max(ans,A[N][M][i]);
        if(ans == A[N][M][i]) z =i;}
    string X;
    while(true) {
        int z0 =z;
        int q =ako[x][y][z];
        z =q%200; q /=200;
        y =q%200; x =q/200;
        if(s[x] == t[y] && next[z][s[x]-'A'] == z0) X +=s[x];
        if(x == 0) break;}
    if(X.empty()) {cout << "0\n"; return 0;}
    for(int i =X.length()-1; i >= 0; i--) cout << X[i];
    cout << "\n";
    return 0;}
        
// look at my code
// my code is amazing