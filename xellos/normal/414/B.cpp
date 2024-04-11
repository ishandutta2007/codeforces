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
    long long mod =1000000007;
    
    vector< vector<long long> > A(K+1,vector<long long>(N+1,0));
    
    vector< vector<int> > D(N+1);
    for(int i =1; i <= N; i++) for(int j =1; j <= i; j++)
        if(i%j == 0) D[i].push_back(j);
    
    for(int i =1; i <= N; i++) A[1][i]++;
    for(int k =2; k <= K; k++) for(int n =1; n <= N; n++)
        ALL_THE(D[n],it) A[k][n] =(A[k][n]+A[k-1][*it])%mod;
        
    long long ans =0;
    for(int i =1; i <= N; i++) ans =(ans+A[K][i])%mod;
    if(ans < 0) ans +=mod;
    cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing