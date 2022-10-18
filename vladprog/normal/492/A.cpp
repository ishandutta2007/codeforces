#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int k=1;
    while(n>=k*(k+1)/2)
        n-=k*(k+1)/2,k++;
    printf("%d",k-1);
}