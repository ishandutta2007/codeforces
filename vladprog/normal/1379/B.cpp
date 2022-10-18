#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

void solve()
{
    int l,r,m;
    cin>>l>>r>>m;
    for(int a=l;a<=r;a++)
    {
        int b_c=m%a;
        if(b_c<=r-l&&m-b_c>0)
        {
            cout<<a<<" "<<l+b_c<<" "<<l<<"\n";
            return;
        }
        b_c=m%a-a;
        if(b_c>=l-r)
        {
            cout<<a<<" "<<l<<" "<<l-b_c<<"\n";
            return;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
}