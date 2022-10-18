#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],t[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>t[i];
    map<int,vector<pii>> m;
    for(int i=1;i<=n;i++)
        m[a[i]].push_back({t[i],a[i]});
    multiset<pii,greater<pii>> s;
    int ans=0;
    for(int cur=0;;cur++)
    {
        if(s.empty())
            cur=m.begin()->x;
        if(!m.empty()&&m.begin()->x==cur)
        {
            for(pii p:m.begin()->y)
                s.insert(p);
            m.erase(m.begin());
        }
        if(s.empty())
            break;
        ans+=s.begin()->x*(cur-s.begin()->y);
        s.erase(s.begin());
    }
    cout<<ans;
}