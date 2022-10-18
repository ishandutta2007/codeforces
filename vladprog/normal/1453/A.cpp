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
        set<int> s;
        for(int i=1;i<=n+m;i++)
        {
            int x;
            cin>>x;
            s.insert(x);
        }
        cout<<n+m-s.size()<<"\n";
    }
}