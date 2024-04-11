#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%i",&n);
    int k=n/2;
    if(n%2==1)printf("%i",2*(k+1)*(k+2));
    else printf("%i",(n/2+1)*(n/2+1));
    return 0;
}