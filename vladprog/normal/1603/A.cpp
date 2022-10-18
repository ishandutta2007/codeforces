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
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        while(!v.empty())
        {
            bool ok=false;
            for(int i=v.size()-1;i>=0;i--)
                if(v[i]%(i+2))
                {
                    v.erase(v.begin()+i);
                    ok=true;
                    break;
                }
            if(!ok)
                break;
        }
        cout<<(v.empty()?"YES\n":"NO\n");
    }
}