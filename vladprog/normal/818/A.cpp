#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k;
    scanf("%I64d%I64d",&n,&k);
    long long p=n/2/(k+1);
    printf("%I64d %I64d %I64d",p,p*k,n-p*(k+1));
}