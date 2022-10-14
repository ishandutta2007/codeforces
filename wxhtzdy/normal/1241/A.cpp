#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        if(n<4)printf("%i\n",4-n);
        else printf("%i\n",n%2);
    }
    return 0;
}