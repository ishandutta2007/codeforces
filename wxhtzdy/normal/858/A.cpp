#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;scanf("%lld",&n);
    int k;scanf("%i",&k);
    int cnt2=0,cnt5=0;
    while(n%2==0)n/=2,cnt2++;
    while(n%5==0)n/=5,cnt5++;
    for(int i=0;i<max(cnt2,k);i++)n*=2;
    for(int i=0;i<max(cnt5,k);i++)n*=5;
    printf("%lld",n);
    return 0;
}