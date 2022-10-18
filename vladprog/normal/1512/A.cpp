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
        int n;
        cin>>n;
        map<int,vector<int>> cnt;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            cnt[a].push_back(i);
        }
        for(auto p:cnt)
            if(p.y.size()==1)
                cout<<p.y[0]<<"\n";
    }
}