#include <bits/stdc++.h>

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
        int n,m;
        cin>>n>>m;
        set<int> center;
        for(int i=1;i<=n;i++)
            center.insert(i);
        while(m--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            center.erase(b);
        }
        for(int i=1;i<=n;i++)
            if(i!=*center.begin())
                cout<<*center.begin()<<" "<<i<<"\n";
    }
}