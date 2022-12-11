#include <bits/stdc++.h>
using namespace std;
int v[1003];
int fv[1003],ocp[1003];
int rz[2003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t,n,m,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int k=0;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            ++v[i];
            ocp[i]=0;
            fv[i]=0;
        }
        fv[n+1]=0;
        for(j=1;j<=n;++j)
        {
            for(i=1;i<=n;++i)
                ++fv[v[i]];
            for(i=1;i<=n+1;++i)
                if(fv[i]==0)
                    break;
            if(i==n+1)
            {
                for(i=1;i<=n;++i)
                    if(!ocp[i])
                        break;
                v[i]=n+1;
                rz[++k]=i;
                for(i=1;i<=n+1;++i)
                    fv[i]=0;
                for(i=1;i<=n;++i)
                    ++fv[v[i]];
                for(i=1;i<=n+1;++i)
                    if(fv[i]==0)
                        break;
            }
            rz[++k]=i;
            v[i]=i;
            ocp[i]=1;
            for(i=1;i<=n+1;++i)
                fv[i]=0;
        }
        cout<<k<<'\n';
        for(i=1;i<=k;++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
    return 0;
}