#include <bits/stdc++.h>
using namespace std;
int mn[100005],ok[100005],vc[100005],cmx[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,w,t,i,j,k=0,pas=1<<15,m,sc,cnt=2;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>m;
        ok[i]=1;
        for(j=1;j<=m;++j)
        {
            cin>>vc[j];
            if(j>=2)
            {
                if(vc[j]>vc[j-1])
                    ok[i]=0;
            }
        }
        if(ok[i])
        {
            ++cmx[vc[1]];
            mn[i]=vc[m];
        }
    }
    for(i=0;i<=1000000;++i)
        cmx[i]+=cmx[i-1];
    for(i=1;i<=n;++i)
    {
        if(ok[i])
        {
            k+=cmx[mn[i]];
        }
    }
    cout<<n*1LL*n-k;
    return 0;
}