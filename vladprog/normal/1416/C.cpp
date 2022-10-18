#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> a(1,vector<int>(n));
    for(int i=0;i<n;i++)
        cin>>a[0][i];
    ll ans=0;
    int x=0;
    for(int i=30;i>=0;i--)
    {
        ll ans0=0,ans1=0;
        vector<vector<int>> b;
        for(auto v:a)
        {
            vector<int> v0,v1;
            for(int e:v)
            {
                int cur=(e>>i)&1;
                if(cur)
                    ans1+=v0.size(),
                    v1.push_back(e);
                else
                    ans0+=v1.size(),
                    v0.push_back(e);
            }
            if(!v0.empty())
                b.push_back(v0);
            if(!v1.empty())
                b.push_back(v1);
        }
        if(ans1<ans0)
            x|=1<<i;
        ans+=min(ans0,ans1);
        a=b;
    }
    cout<<ans<<" "<<x;
}