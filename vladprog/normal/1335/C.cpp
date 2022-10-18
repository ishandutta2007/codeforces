#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mx=0;
        map<int,int> cnt;
        while(n--)
        {
            int x;
            cin>>x;
            mx=max(mx,++cnt[x]);
        }
        int ans1=min<ll>(cnt.size()-1,mx);
        int ans2=min<ll>(cnt.size(),mx-1);
        cout<<max(ans1,ans2)<<"\n";
    }
}