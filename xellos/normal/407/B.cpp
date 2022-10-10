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
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i =0; i < N; i++) {
        cin >> P[i];
        P[i]--;}
    
    vector<long long> p(N+patkan,1);
    long long mod =1000000007;
    for(int i =1; i <= N; i++) p[i] =(p[i-1]*2)%mod;
    
    vector<long long> A(N,2);
    long long ans =0;
    for(int i =0; i < N; i++) {
        for(int j =P[i]; j < i; j++) A[i] =(A[i]+A[j])%mod;
        ans =(ans+A[i])%mod;}
    cout << ans%mod << "\n";
    return 0;}
        
// look at my code
// my code is amazing