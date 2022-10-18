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
        int n,k;
        cin>>n>>k;
        set<int> s;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            s.insert(x);
        }
        if(s.size()>k)
        {
            cout<<-1<<"\n";
            continue;
        }
        for(int i=1;i<=n&&s.size()<k;i++)
            s.insert(i);
        cout<<n*k<<"\n";
        for(int i=1;i<=n;i++)
            for(int x:s)
                cout<<x<<" ";
        cout<<"\n";
    }
}