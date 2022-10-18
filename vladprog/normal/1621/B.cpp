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
        pii M(2e9,2e9),L(2e9,2e9),R(2e9,2e9);
        while(n--)
        {
            int l,r,c;
            cin>>l>>r>>c;
            M=min(M,pii(l-r,c));
            L=min(L,pii(l,c));
            R=min(R,pii(-r,c));
            if(L.x+R.x==M.x)
                cout<<min(M.y,L.y+R.y)<<"\n";
            else
                cout<<L.y+R.y<<"\n";
        }
    }
}