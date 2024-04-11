#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
int a[N],b[N],id[N];
int main()
{
    int n,i,c=0;
    scanf("%i",&n);
    for(i=1;i<=n;i++) scanf("%i",&a[i]),id[a[i]]=i;
    for(i=1;i<=n;i++)
    {
        scanf("%i",&b[i]);
        if(id[b[i]]>c)
        {
            printf("%i ",id[b[i]]-c);
            c=id[b[i]];
        }
        else printf("0 ");
    }
    return 0;
}