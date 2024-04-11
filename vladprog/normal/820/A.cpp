#include<bits/stdc++.h>

using namespace std;

int main()
{
    int c,v0,v1,a,l;
    scanf("%d%d%d%d%d",&c,&v0,&v1,&a,&l);
    int n=v0,k=1;
    while(n<c)
    {
        n-=l;
        v0=min(v0+a,v1);
        n+=v0;
        k++;
    }
    printf("%d",k);
}