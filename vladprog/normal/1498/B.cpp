#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,w;
        cin>>n>>w;
        map<int,int,greater<int>> cnt;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            cnt[x]++;
        }
        int ans=0;
        while(n>0)
        {
            int cur=w;
            for(auto&[x,k]:cnt)
                while(cur>=x&&k>0)
                    cur-=x,
                    k--,
                    n--;
            ans++;
        }
        cout<<ans<<"\n";
    }
}