#include<bits/stdc++.h>

using namespace std;

const int inf=1e9+1;

int main()
{
    int n;
    scanf("%i",&n);
    int I=-1,L=inf,R=0;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        scanf("%i%i",&l,&r);
        if(l<L||r>R)
            I=-1;
        L=min(L,l);
        R=max(R,r);
        if(L==l&&R==r)
            I=i;
    }
    printf("%i\n",I);
}