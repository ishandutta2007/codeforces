#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int a,b,c,d;
        scanf("%i %i %i %i",&a,&b,&c,&d);
        printf("%i\n",max(a+b,c+d));
    }
    return 0;
}