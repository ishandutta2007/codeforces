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
        if(n%2)
            cout<<n/2<<" "<<n/2<<" "<<1<<"\n";
        else if(n%4)
            cout<<n/2-1<<" "<<n/2-1<<" "<<2<<"\n";
        else
            cout<<n/2<<" "<<n/4<<" "<<n/4<<"\n";
    }
}