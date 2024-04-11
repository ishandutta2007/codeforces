#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n,x,L,R,l,r;
int main()
{
    scanf("%d%d",&n,&x);
    l=r=x; long long ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&L,&R);
        if(max(L,l)<=min(R,r))
        {
            l=max(L,l); r=min(R,r);
        }
        else if(R<l)
        {
            ans+=l-R; r=l; l=R;
        }
        else
        {
            ans+=L-r; l=r; r=L;
        }
    }
    printf("%I64d\n",ans);
}