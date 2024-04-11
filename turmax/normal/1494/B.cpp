#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,u,r,d,l;
        cin>>n>>u>>r>>d>>l;
        vector <int> v={u,r,d,l};
        vector <int> v1;
        bool ok=false;
        for(int mask=0;mask<16;++mask)
        {
            v1=v;
            for(int i=0;i<4;++i)
            {
                if(mask & (1<<i))
                {
                    v1[i]--;
                    v1[(i+1)%4]--;
                }
            }
            bool z=false;
            for(auto h:v1)
            {
                if(h<0 || h>(n-2))
                {
                    z=true;
                }
            }
            if(!z)
            {
                ok=true;
            }
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}