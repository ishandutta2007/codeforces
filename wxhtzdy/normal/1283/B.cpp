#include <bits/stdc++.h>
using namespace std;
int main(){
    int tt;scanf("%i",&tt);
    while(tt--){
        int n,k;scanf("%i%i",&n,&k);
        printf("%i\n",(int)(n/k)*k+min(n%k,k/2));
    }
    return 0;
}