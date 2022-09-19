#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int int_fast32_t
const int maxn=2e6+10;
int cnt[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        int b[n];
        bool ok=false;
        for(int u=2e6+5;u>=1;--u)
        {
            int f=0;
            for(int i=0;i<n;++i)
            {
                b[i]=(a[i]%u);if(b[i]<0) b[i]+=u;
                cnt[b[i]]++;
                f=max(f,cnt[b[i]]);
            }
            for(int j=0;j<n;++j) cnt[b[j]]--;
            if(f>=(n/2))
            {
                if(u==(2e6+5))
                {
                    cout<<(-1)<<endl;
                    break;
                }
                cout<<u<<endl;
                ok=true;
                break;
            }
        }
    }
    return 0;
}