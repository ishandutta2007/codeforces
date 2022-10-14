#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int a,b;scanf("%i %i",&a,&b);
        int diff=abs(a-b);
        for(int i=0;i<=1e6;i++){
            int x=i*(i+1)/2;
            if(diff<=x&&x%2==diff%2){
                printf("%i\n",i);
                break;
            }
        }
    }
    return 0;
}