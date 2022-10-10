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
// mylittlepony
using namespace std;

int ans(int x) {if(x<0) return -x; else return x;}

int main() {
    int N,K;
    scanf(" %d %d",&N,&K);
    vector<int> A(N);
    ALL_THE(A,it) scanf(" %d",&(*it));
    sort(A.begin(),A.end());
    
    if(K <= N) printf("%d %d\n",A[N-K],A[N-K]);
    else printf("-1\n");
    return 0;}
        
// look at my code
// my code is amazing