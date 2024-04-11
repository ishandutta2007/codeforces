#include <bits/stdc++.h>
using namespace std;
const int maxn=25;
int a[maxn],b[maxn],c[maxn],n,m,ans;
bool cmp(int i,int j)
{
    return b[i]>b[j];
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        c[i]=i;
        cin>>a[i]>>b[i];
    }
    sort(c+1,c+m+1,cmp);
    ans=0;
    for(int i=1;i<=m;i++)
    {
        if (n>=a[c[i]])
        {
            n-=a[c[i]];
            ans+=a[c[i]]*b[c[i]];
        }
        else
        {
            ans+=n*b[c[i]];
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}