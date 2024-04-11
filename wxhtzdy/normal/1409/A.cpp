#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int a,b;
        scanf("%i %i",&a,&b);
        printf("%i\n",(abs(a-b)+9)/10);
    }
    return 0;
}