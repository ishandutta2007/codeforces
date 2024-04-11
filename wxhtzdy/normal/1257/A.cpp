#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n,x,a,b;scanf("%i %i %i %i",&n,&x,&a,&b);
        printf("%i\n",min(n-1,max(a,b)-min(a,b)+x));
    }
    return 0;
}