#include <bits/stdc++.h>

using namespace std;
int v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,d,i,j,t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>n>>x;
        int ok=0;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            if(v[i]==x)
            {
                ok=1;
            }
        }
        if(ok)
        {
            cout<<"1\n";
            continue;
        }
        sort(v+1,v+n+1);
        if(v[n]*2LL>=x)
        {
            cout<<"2\n";
            continue;
        }
        x-=v[n]*2LL;
        long long cat=(x-1LL)/v[n]+1;
        cout<<cat+2<<'\n';
    }
    return 0;
}