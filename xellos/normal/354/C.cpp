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
    int N,K,a =1000000;
    cin >> N >> K;
    vector<int> A(N);
    for(int i =0; i < N; i++) {
        cin >> A[i];
        a =min(a,A[i]);}
    if(K >= a) {cout << a << "\n"; return 0;}
    
    vector<int> S(1000000+tisic,0);
    for(int i =0; i < N; i++) {
        S[A[i]]++;
        S[max(0,A[i]-K-1)]--;}
    for(int i =1000000; i >= 0; i--) S[i] +=S[i+1];
    
    for(int d =a; d >= K; d--) {
        int x =0;
        for(int i =1; i <= 1000000/d; i++) x +=S[i*d];
        if(x == N) {cout << d << "\n"; return 0;}
        }
    return 0;}
        
// look at my code
// my code is amazing