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
    int N,K,a;
    scanf(" %d %d",&N,&K);
    if(K == 1) {
        printf("%d\n",N);
        return 0;}
    map<int,int> V;
    for(int i =0; i < N; i++) {
        scanf(" %d",&a);
        V[a] =0;}
    ALL_THE(V,it) if((it->first)%K == 0 && V.find((it->first)/K) != V.end()) 
        it->second =1+V[(it->first)/K];
    a =0;
    ALL_THE(V,it) a +=1-it->second%2;
    printf("%d\n",a);
    return 0;}
        
// look at my code
// my code is amazing