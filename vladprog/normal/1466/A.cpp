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
        int x[n+5];
        for(int i=1;i<=n;i++)
            cin>>x[i];
        set<int> s;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                s.insert(x[j]-x[i]);
        cout<<s.size()<<"\n";
    }
}