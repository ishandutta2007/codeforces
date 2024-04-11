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
        int n,k;
        cin>>n>>k;
        int ans=(k+n-1)/n;
        if(ans>=2)
            cout<<ans<<"\n";
        else if(n%k==0)
            cout<<1<<"\n";
        else
            cout<<2<<"\n";
    }
}