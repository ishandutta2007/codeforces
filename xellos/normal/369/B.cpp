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
#include <cmath>
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
    int N,K,L,R,Sa,Sk;
    cin >> N >> K >> L >> R >> Sa >> Sk;
    vector<int> A(N);
    if(K > 0) {
        for(int i =0; i < K; i++) A[i] =Sk/K;
        for(int i =0; i < Sk%K; i++) A[i]++;}
    if(N-K > 0) {
        Sa -=Sk;
        for(int i =N-1; i >= K; i--) A[i] +=Sa/(N-K);
        for(int i =K; i < K+Sa%(N-K); i++) A[i]++;}
    for(int i =0; i < N; i++) cout << A[i] << ((i == N-1)?"\n":" ");
    return 0;}

// look at my code
// my code is amazing