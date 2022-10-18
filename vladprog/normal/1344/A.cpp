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
        int n;
        cin>>n;
        set<int> a;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            x+=i;
            x%=n;
            x+=n;
            x%=n;
            a.insert(x);
        }
        cout<<(a.size()==n?"YES\n":"NO\n");
    }
}