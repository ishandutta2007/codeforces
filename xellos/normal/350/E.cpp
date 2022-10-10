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
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// mylittlepony
using namespace std;
    
int main() {
    int N,M,K,a;
    cin >> N >> M >> K;
    if(K == N) {cout << "-1\n"; return 0;}
    vector<bool> A(N,false);
    for(int i =0; i < K; i++) {cin >> a; A[--a] =true;}

    int b,c;
    for(int i =0; i < N; i++) if(!A[i]) a =i;
    for(int i =0; i < N; i++) if(A[i]) b =i;
    for(int i =0; i < N; i++) if(i != a && i != b) c =i;
    if(M > N*(N-1)/2-K+1) {cout << "-1\n"; return 0;}
    
    cout << b+1 << " " << a+1 << "\n";
    int k =M-1;
    for(int i =0; i < N; i++) for(int j =i+1; j < N; j++) {
        if(i == b && A[j]) continue;
        if(j == b && A[i]) continue;
        if(i == a && j == b) continue;
        if(i == b && j == a) continue;
        cout << i+1 << " " << j+1 << "\n";
        k--;
        if(k == 0) return 0;}
    return 0;}
        
// look at my code
// my code is amazing