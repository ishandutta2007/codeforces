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

long long mod =1000000007;
    
int main() {
    cin.sync_with_stdio(0);
    int N,K;
    string s;
    cin >> N >> K >> s;
    
    vector< vector<long long> > A(K+1,vector<long long>(N+1,0));
    vector< vector<long long> > S(K+1,vector<long long>(N+1,0));
    // kolko je moznosti ak sme fixli i pismen, z toho k rovnakych s, a vysledok zatial je j?
    A[0][0] =1;
    for(int i =0; i < N; i++) for(int j =0; j <= K; j++) {
        S[j][i+1] =(S[j][i]+A[j][i])%mod;
        if(S[j][i+1] < 0) S[j][i+1] +=mod;
        // t[i] < s[i]
        A[j][i+1] =(A[j][i+1]+S[j][i+1]*(s[i]-'a'))%mod;
        if(A[j][i+1] < 0) A[j][i+1] +=mod;
        // t[i] > s[i]
        int y =min(i,(K-j)/(N-i)-1);
        for(int k =0; k <= y; k++) {
            int x =j+(k+1)*(N-i);
            A[x][i+1] =(A[x][i+1]+A[j][i-k]*('z'-s[i]))%mod;
            if(A[x][i+1] < 0) A[x][i+1] +=mod;}
        }
    
    long long ans =0;
    for(int i =0; i <= N; i++) ans =(ans+A[K][i])%mod;
    if(ans < 0) ans +=mod;
    cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing