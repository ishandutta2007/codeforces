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
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i =0; i < N; i++) cin >> A[i];
    sort(A.begin(),A.end());
    
    long long x =A[N-1]-1, y =100000000000000LL;
    while(y-x > 1) {
        long long z =(x+y)/2;
        long long S =0;
        for(int i =0; i < N; i++) S +=z-A[i];
        bool ok =true;
        for(int i =0; i < N; i++) 
            if(S-A[i] < z-A[i]) ok =false;
        if(ok) y =z;
        else x =z;}
    cout << y << "\n";
    return 0;}
        
// look at my code
// my code is amazing