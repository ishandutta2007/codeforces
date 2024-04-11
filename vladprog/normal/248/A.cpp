#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int L=0,R=0;
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        L+=l;
        R+=r;
    }
    L=min(L,n-L);
    R=min(R,n-R);
    printf("%d\n",L+R);
}