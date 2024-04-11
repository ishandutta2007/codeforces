#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    int n,k;
    scanf("%i %i",&n,&k);
    vector<int> niz(n);
    int sum=0;
    for(int i=0;i<n;i++)
        scanf("%i",&niz[i]),sum+=niz[i];
    if(sum%k!=0)
    {
        printf("No\n");
        return 0;
    }
    k=sum/k;
    vector<int> sizes;
    int tr=0;
    int last=0;
    for(int i=0;i<n;i++)
    {
        //printf("Usao za %i; %i\n",i,niz[i]);
        if(tr==k)
        {
            sizes.pb(i-last);
            tr=0;
            last=i;
        }
        if(tr+niz[i]>k)
        {
            printf("No\n");
            return 0;
        }
        tr+=niz[i];
    }
    if(tr==k)
    {
        sizes.pb(n-last);
    }
    else
    {
        assert(0);
    }
        printf("Yes\n");
    for(int i=0;i<sizes.size();i++)
    {
        printf("%i ",sizes[i]);
    }
    return 0;
}