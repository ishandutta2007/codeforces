#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

bool solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++,cout<<"\n")
        for(int j=1;j<=m;j++)
        {
            int val;
            cin>>val;
            if((val+i+j)%2)
                val++;
            cout<<val<<" ";
        }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0)^(int)(new char));

    int t;
    cin>>t;
    while(t--)
        solve();
}