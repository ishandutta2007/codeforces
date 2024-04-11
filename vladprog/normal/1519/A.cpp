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
        int r,b,d;
        cin>>r>>b>>d;
        if(r>b)
            swap(r,b);
        cout<<(r*(d+1)>=b?"YES\n":"NO\n");
    }
}