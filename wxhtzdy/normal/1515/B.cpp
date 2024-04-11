#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        if(n%2==0&&(int)sqrt(n/2)*(int)sqrt(n/2)==n/2){
            printf("YES\n");
        }else{
            if(n%4==0&&(int)sqrt(n/4)*(int)sqrt(n/4)==n/4){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}