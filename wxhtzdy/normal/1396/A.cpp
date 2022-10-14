#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%i",&n);
    long long a[n];
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    if(n==1){
        printf("1 1\n0\n1 1\n0\n1 1\n%i",-a[0]);
        return 0;
    }
    printf("1 1\n%i\n",-a[0]);
    printf("1 %i\n",n);
    printf("0 ");
    for(int i=1;i<n;i++)printf("%lld ",-a[i]*n);
    printf("\n2 %i\n",n);
    for(int i=1;i<n;i++)printf("%lld ",a[i]*(n-1));
    return 0;
}