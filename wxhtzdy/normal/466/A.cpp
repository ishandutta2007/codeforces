#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
int main(){
    scanf("%i%i%i%i",&n,&m,&a,&b);
    int k=n/m;
    if(n<m)k=1;
    int np=b*k;
    if(n%m&&n>m)np+=min(a*(n%m),b);
    printf("%i",min(np,a*n));
}