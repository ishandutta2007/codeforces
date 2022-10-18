#include<bits/stdc++.h>
using namespace std;
int minn[40],maxn[40];
int ans[40];
int m,n;
int main()
{
    cin>>m>>n;
    int c,d,e;
    int max=0,min=0;
    for(c=0;c<m;c++)
    {
        scanf("%d %d",&minn[c],&maxn[c]);
        max+=maxn[c];
        min+=minn[c];
    }
    if(max<n||min>n)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(c=0;c<m;c++)
    {
    	ans[c]=minn[c];
    }
    int t=n-min;
    for(c=0;;c++)
    {
        if(maxn[c]-ans[c]<=t)
        {
            ans[c]=maxn[c];
            t-=(maxn[c]-minn[c]);
            continue;
        }
        else
        {
            ans[c]+=t;
            break;
        }
    }
    for(c=0;c<m;c++)
    {
        printf("%d ",ans[c]);
    }
    cout<<"\n";
    return 0;
}