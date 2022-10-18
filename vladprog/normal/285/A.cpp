#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=k+1;i>=1;i--)printf("%d ",i);
    for(int i=k+2;i<=n;i++)printf("%d ",i);
}