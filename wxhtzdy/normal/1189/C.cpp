#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    int p[n];
    p[0]=a[0];
    for(int i=1;i<n;i++)p[i]=p[i-1]+a[i];
    int q;
    scanf("%i",&q);
    while(q--){
        int l,r;
        scanf("%i %i",&l,&r);
        --l,--r;
        printf("%i\n",(p[r]-(l==0?0:p[l-1]))/10);
    }
    return 0;
}