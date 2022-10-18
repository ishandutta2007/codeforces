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
        int down=1e9,up=0;
        bool ok=true;
        while(n--)
        {
            int a;
            cin>>a;
            if(a-up<0)
                ok=false;
            down=min(down,a-up);
            up=a-down;
        }
        cout<<(ok?"YES\n":"NO\n");
    }
}