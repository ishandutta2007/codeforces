#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    int x[n];
    for(int i=0;i<n;i++)
        scanf("%d",&x[i]);
    int m=0;
    for(int i=0;i<n-1;i++)
        m=max(m,x[i]-x[i+1]-c);
    printf("%d",m);
}