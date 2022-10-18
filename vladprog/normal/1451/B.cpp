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
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        s="_"+s;
        int lef=1;
        while(lef<n&&s[lef+1]==s[1])
            lef++;
        int rig=n;
        while(rig>1&&s[rig-1]==s[n])
            rig--;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            if((l==1||l==lef+1)&&
               (r==n||r==rig-1))
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
    }
}