#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n;
        scanf("%i",&n);
        int a[n],sum=0,mx=0;
        for(int i=0;i<n;i++)scanf("%i",&a[i]),sum+=a[i],mx=max(mx,a[i]);
        if(sum-mx<mx){
            printf("T\n");
            continue;
        }
        if(sum&1)printf("T\n");
        else printf("HL\n");
    }
    return 0;
}