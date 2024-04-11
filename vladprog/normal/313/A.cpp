#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",max(n,max(n/10,n/100*10+n%10)));
}