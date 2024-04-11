#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    scanf("%i%i",&n,&k);
    int cnt=n,cnt2=0,j=k;
    while(n>=k)cnt2+=n/k,n=(n%k)+n/k;
    printf("%i",cnt+cnt2);
}