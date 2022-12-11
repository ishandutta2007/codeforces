#include <bits/stdc++.h>
using namespace std;
int v[103];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,m,k=0,x=0,t,s=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(i=1;i<=n;++i)
    {
        if(v[i]!=-1)
        {
            for(j=i+1;j<=n;++j)
                if(v[j]%v[i]==0)
                    v[j]=-1;
            v[i]=-1;
            ++s;
        }
    }
    cout<<s;
    return 0;
}