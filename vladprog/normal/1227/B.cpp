#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        set<int> s;
        for(int i=1;i<=n;i++)
            s.insert(i);
        vector<int> p;
        bool ok=true;
        while(n--)
        {
            int q;
            cin>>q;
            if(!ok)
                continue;
            auto it=s.upper_bound(q);
            if(it==s.begin())
            {
                ok=false;
                continue;
            }
            it--;
            p.push_back(*it);
            s.erase(it);
        }
        if(ok)
        {
            for(int x:p)
                cout<<x<<" ";
            cout<<"\n";
        }
        else
            cout<<-1<<"\n";
    }
}