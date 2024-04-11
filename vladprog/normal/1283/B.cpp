#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

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
        int d=n/k;
        int r=n%k;
        cout<<d*k+min(r,k/2)<<"\n";
    }
}