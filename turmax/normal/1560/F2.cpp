#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
int po[11];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    po[0]=1;for(int i=1;i<=10;++i) po[i]=po[i-1]*10;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        while(true)
        {
            string s=to_string(n);
            set <char> o;
            bool fst[s.size()]={0};
            for(int i=0;i<s.size();++i)
            {
                if(!o.count(s[i]))
                {
                    o.insert(s[i]);
                    fst[i]=true;
                }
            }
            int ans=o.size();
            if(ans<=k)
            {
                cout<<n<<endl;
                break;
            }
            int o1=(-1);int cnt=0;
            for(int i=s.size()-1;i>=0;i--)
            {
                if(!fst[i])
                {
                    ++o1;
                    continue;
                }
                ++cnt;
                ++o1;
                if(cnt>=(ans-k))
                {
                    break;
                }
            }
            if(n%po[o1]==0) ++n;
            else n=((n+po[o1]-1)/po[o1])*po[o1];
        }
    }
    return 0;
}