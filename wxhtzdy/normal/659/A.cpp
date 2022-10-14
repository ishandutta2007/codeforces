#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    scanf("%i %i %i",&n,&a,&b);
    b%=n;a--;a=(a+b+n)%n;
    printf("%i",a+1);
}