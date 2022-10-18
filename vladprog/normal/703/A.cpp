#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int M=0,C=0;
    for(int i=0;i<n;i++)
    {
        int m,c;
        scanf("%d%d",&m,&c);
        if(m>c)
            M++;
        else if(c>m)
            C++;
    }
    if(M>C)
        printf("Mishka");
    else if(C>M)
        printf("Chris");
    else
        printf("Friendship is magic!^^");
}