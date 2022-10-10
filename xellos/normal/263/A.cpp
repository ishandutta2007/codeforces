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
    int a;
    for(int i =0; i < 5; i++) for(int j =0; j < 5; j++) {
        scanf(" %d",&a);
        if(a == 1) {
            printf("%d\n",abs(i-2)+abs(j-2));
            return 0;}
        }
    return 0;}
        
// look at my code
// my code is amazing