#include <bits/stdc++.h>
using namespace std;

int n, cnt, i;
int main(){
    for(scanf("%d",&n),i=1;i<31;i++){
        if((1<<i)-1>=n){
            printf("%d\n",i-1+((1<<i)!=n));
            return 0;
        }
    }
}