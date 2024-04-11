#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k;
    scanf("%I64d%I64d",&n,&k);
    n--;
    k--;
    if((k*(k+1)/2)<n)return printf("-1"),0;
    int c=0;
    while(n>0)
        n-=k-c++;
    printf("%d",c);
}