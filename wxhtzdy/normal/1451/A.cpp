#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        if(n==1)printf("0\n");
        if(n==2)printf("1\n");
        if(n==3)printf("2\n");
        if(n>3)printf("%i\n",2+n%2);
    }
    return 0;
}