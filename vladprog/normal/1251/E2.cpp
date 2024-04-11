#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,INF=1e18;

pii mp[N];

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
        for(int i=0;i<n;i++)
            cin>>mp[i].x>>mp[i].y;
        sort(mp,mp+n);
        for(int i=0;i<n;i++)
            mp[i].x-=i;
        multiset<int> s;
        int cnt=0,sum=0;
        for(int i=n-1;i>=0;i--)
        {
            s.insert(mp[i].y);
            if(cnt<mp[i].x)
                cnt++,
                sum+=*s.begin(),
                s.erase(s.begin());
        }
        cout<<sum<<"\n";
    }
}