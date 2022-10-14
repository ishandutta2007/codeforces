#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    int n,k;
    scanf("%i%i",&n,&k);
    if(k>0&&k<n)printf("1 ");
    else {printf("0 0");return 0;};
    int h=n/2+n%2;
    printf("%i",min(n-k,2*k));
}