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
	
int main() {
    int N, ans =0;
    scanf(" %d\n",&N);
    char c,co ='a';
    for(int i =0; i < N; i++) {
        scanf("%c",&c);
        if(c == co) ans++;
        co =c;}
    printf("%d\n",ans);
    return 0;}
        
// look at my code
// my code is amazing