#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int MOD=998244353;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        list<int> a;
        map<int,list<int>::iterator> where;
        a.push_back(0);
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            a.push_back(x);
            where[x]=prev(a.end());
        }
        a.push_back(0);
        vector<int> b;
        set<int> s{0};
        for(int i=1;i<=k;i++)
        {
            int x;
            cin>>x;
            b.push_back(x);
            s.insert(x);
        }
        int ans=1;
        for(int x:b)
        {
            auto it=where[x];
            s.erase(x);
            int l=*prev(it),r=*next(it);
//            cout<<x<<" -> "<<l<<" "<<r<<"\n";
            if(s.count(l))
                if(s.count(r))
                {
                    ans=0;
                    break;
                }
                else
                    a.erase(next(it));
            else
                if(s.count(r))
                    a.erase(prev(it));
                else
                    a.erase(next(it)),
                    ans=ans*2%MOD;
        }
        cout<<ans<<"\n";
    }
}